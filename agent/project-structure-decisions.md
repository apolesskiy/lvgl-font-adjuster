# Project Structure Decisions

## 2026-03-02: Separate parser/ and serializer/ directories
* **Decision**: Keep parser and serializer in separate directories rather than a single `io/` directory.
* **Rationale**: They have distinct responsibilities and different testing needs. The parser converts text→model; the serializer converts model→text. Separating them makes each easier to test and reason about independently.

## 2026-03-02: Tests outside src/
* **Decision**: Place tests under a top-level `tests/` directory rather than co-locating with source files.
* **Rationale**: Keeps `src/` focused on shipped code. The `tests/` directory mirrors the source structure for discoverability.
