# 위상 정렬과 Git 기초 연습

KAIST 수업에서 작성한 C++ 위상 정렬 코드와 Git 업로드 연습 기록입니다. 서비스나 배포용 라이브러리가 아니라 학습 저장소입니다.

## 해결하는 문제

정점 사이의 선후 관계가 주어졌을 때, 모든 방향 간선을 만족하는 처리 순서를 구합니다. [topologicalsort.cpp](topologicalsort.cpp)는 진입 차수가 0인 정점을 큐에서 꺼내 다음 정점의 진입 차수를 줄이는 Kahn 알고리즘을 구현합니다.

## 실행

```bash
c++ -std=c++17 -Wall -Wextra -pedantic topologicalsort.cpp -o /tmp/topologicalsort
printf '4 3\n1 2\n1 3\n3 4\n' | /tmp/topologicalsort
```

입력은 `N M`과 `M`개의 `A B` 간선이며, 정점 번호는 `1..N`입니다. 위 예제의 출력 순서는 `1 2 3 4`입니다. 일반적으로 정답 순서는 하나가 아닐 수 있습니다.

## 학습과 현재 한계

큐와 진입 차수를 사용해 매번 모든 정점을 재검색하지 않고 `O(N+M)`에 순서를 생성하는 방법을 구현했습니다. 다만 현재 코드는 DAG 입력을 전제로 하며 순환 탐지나 잘못된 정점 입력 검증을 하지 않습니다. 자동 테스트·CI·라이브러리 배포 경험의 근거로 제시하지 않습니다.

대표 개발 도구와 검증 경험은 [SBOM 분석 도구](https://github.com/leejuyoung0918/sbom-vulnerability-propagation), [재현 가능한 실험 도구](https://github.com/leejuyoung0918/pr-eig-theoretical-experiments)에서 확인할 수 있습니다.
