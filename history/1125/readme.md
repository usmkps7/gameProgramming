# 1. 엔진 설치 & 실행 관련 기능
Epic Games Launcher

Unreal Engine 다운로드 및 버전 관리

프로젝트 목록 관리(My Projects)

샘플 프로젝트 / 애셋(Fab) 관리

엔진 버전별 설치 옵션 선택(C++ 포함 여부 등)

→ 엔진은 Launcher에서만 관리되며, 기본 경로 외 저장 시 인식 문제 주의 


# 2. 프로젝트 생성 시스템
Development Category (템플릿 분류)

Games

First Person / Third Person

Top Down

Vehicle

VR / AR

Film / Video / Live Events

Virtual Production

In-Camera VFX

nDisplay

Motion Design

Architecture / Product / Manufacturing

Archviz

Collab Viewer

Design Configurator

Simulation

➡️ 작업 목적(게임·영상·건축)에 따라 기본 세팅이 다른 템플릿 제공 


# 3. 에디터 UI & 레이아웃 기능
핵심 UI 구성요소

Viewport : 실제 게임/씬 화면

Outliner : 씬 내 오브젝트 계층 구조(Hierarchy)

Details : 선택한 액터/컴포넋牌 상세 설정

Content Browser : 에셋·스크립트·레벨 관리

Actor Placement : 기본 액터(라이트, 도형 등) 배치

UE4 / UE5 레이아웃 선택 가능 (UI 배치 차이 존재) 


# 4. 기본 조작 & 편집 기능
뷰포트 조작

우클릭 + WASD : 카메라 이동

Q / W / E / R : 선택 / 이동 / 회전 / 스케일

카메라 이동 속도 조절

스냅(Snap) On/Off 및 단위 조절

➡️ 정밀 배치 vs 빠른 배치 전환 가능 


# 5. 레벨(Level) 관리 기능

Content Browser에서 Level 생성

레벨은 씬 단위 데이터

레벨 생성 직후는 완전 빈 상태(검은 화면)

➡️ 레벨 = “게임 월드의 단위” 


# 6. 환경 & 라이팅 시스템
Environment Light Mixer

한 번에 필수 환경요소 자동 생성

주요 라이트/환경 액터

Directional Light : 태양광

Sky Light : 간접광

Sky Atmosphere : 대기 표현

Volumetric Cloud : 실시간 구름

Exponential Height Fog : 안개

➡️ 태양 방향 회전(E키)으로 시간대 변화 시뮬레이션 가능 

# 7. 블루프린트(Blueprint) 시스템
블루프린트 종류

Level Blueprint

특정 레벨 전용 로직

Actor Blueprint

오브젝트 단위 로직 재사용 가능

블루프린트 화면 구성

상태창(Variables, Functions, Events)

이벤트 그래프(Event Graph)

Details (세부 설정)

➡️ 비주얼 스크립팅 기반 로직 설계 

# 8. 입력 시스템 (Enhanced Input)
구조

Input Action (IA_)

Input Mapping Context (IMC_)

특징

키보드/마우스 입력을 액션 단위로 추상화

캐릭터/컨트롤러에 바인딩

블루프린트 & C++ 공용 사용

➡️ UE5의 기본 입력 시스템 

# 9. 캐릭터 & 카메라 시스템
Third Person 템플릿 구조

Pawn (Character)

Controller (Player Controller)

Spring Arm + Camera

Movement Component

동작 로직

이동: Add Movement Input

점프: IA_Jump

시점: 마우스 입력 반영

# 10. C++ 개발 기능
Visual Studio 연동

C++ 게임 개발 옵션 필수

UE ↔ VS 실시간 연동(Live Coding)

기본 Actor 클래스 구조

.h + .cpp

BeginPlay() : 최초 1회 실행

Tick() : 프레임 단위 실행

GEngine->AddOnScreenDebugMessage() : 화면 출력
