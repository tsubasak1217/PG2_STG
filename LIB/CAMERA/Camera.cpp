#include "Camera.h"
#include "InputKey.h"
#include "Environment.h"

Vec2 Camera::range_ = {0};
Vec2 Camera::kRange_ = { 0 };
Vec2 Camera::LT_ = {0};
Vec2 Camera::RB_ = {0};

Vec2 Camera2D::pos_ = {0};
Vec2 Camera2D::scale_ = {1.0f,1.0f};
Vec2 Camera2D::goalScale_ = { 1.0f,1.0f };
float Camera2D::theta_ = {0.0f};
Vec2 Camera2D::shake_ = {0};
Matrix3x3 Camera2D::cameraWorldMatrix_;
Matrix3x3 Camera2D::cameraInverse_;
Matrix3x3 Camera2D::orthoMatrix_;

Vec3 Camera3D::pos_ = {0};
Vec3 Camera3D::scale_ = {1.0f,1.0f,1.0f};
Vec3 Camera3D::theta_ = {0};
Vector3<int> Camera3D::shake_ = {0};

//----------------------------------------------------------------------------------
Camera::Camera(Vec2 range) {
	range_ = range;
	kRange_ = range;
}

Camera::~Camera() {
}

//----------------------------------------------------------------------------------
Camera2D::Camera2D(Vec2 pos, Vec2 range) : Camera(range) {
	pos_ = pos;
	LT_ = pos_ + (range_.operator*({ -0.5f,0.5f }));
	RB_ = pos_ + (range_.operator*({ 0.5f,-0.5f }));
	MakeMatrix();
}

Camera2D::~Camera2D() {
}

void Camera2D::Init() {
}

void Camera2D::Update() {

	goalScale_.x += float(InputKey::mouseWheel) / 600.0f;
	goalScale_.x = std::clamp(goalScale_.x, 0.2f, 4.0f);
	goalScale_.y = goalScale_.x;

	scale_ += (goalScale_ - scale_) * 0.06125f;


	pos_ = (InputKey::worldMousePos_) * 0.00125f;


	// カメラを画面端で止める
	if (pos_.x > stageRB.x - (range_.x * 0.5f) * scale_.x) {
		pos_.x = stageRB.x - (range_.x * 0.5f) * scale_.x;
	}
	if (pos_.x < stageLT.x + (range_.x * 0.5f) * scale_.x) {
		pos_.x = stageLT.x + (range_.x * 0.5f) * scale_.x;
	}

	if (pos_.y > stageLT.y - (range_.y * 0.5f) * scale_.y) {
		pos_.y = stageLT.y - (range_.y * 0.5f) * scale_.y;
	}
	if (pos_.y < stageRB.y + (range_.y * 0.5f) * scale_.y) {
		pos_.y = stageRB.y + (range_.y * 0.5f) * scale_.y;
	}
	//range_ = 
	LT_ = pos_.operator+(shake_) + (range_.operator*({ -0.5f,0.5f }));
	RB_ = pos_.operator+(shake_) + (range_.operator*({ 0.5f,-0.5f }));

	MakeMatrix();
}

void Camera2D::Fin() {
}

void Camera2D::MakeMatrix() {
	cameraWorldMatrix_ = AffineMatrix(scale_, theta_, pos_);
	cameraInverse_ = InverseMatrix(cameraWorldMatrix_);
	orthoMatrix_ = OrthoMatrix(LT_.x, RB_.x, LT_.y, RB_.y);

}

//----------------------------------------------------------------------------------
Camera3D::Camera3D(Vec3 pos, Vec2 range) : Camera(range) {
	pos_ = pos;
	LT_.x = pos_.x - range_.x * 0.5f;
	LT_.y = pos_.y + range_.y * 0.5f;
	RB_.x = pos_.x + range_.x * 0.5f;
	RB_.y = pos_.y - range_.y * 0.5f;
}

Camera3D::~Camera3D() {
}

void Camera3D::Init() {
}

void Camera3D::Update() {
}

void Camera3D::Fin() {
}
