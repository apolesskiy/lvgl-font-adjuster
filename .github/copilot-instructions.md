## Technology Stack
* Refer to `agent/technology-stack.md` for technology stack details.
* When selecting technologies to use (e.g. languages, frameworks, libraries), record the decision in `agent/technology-decisions.md` for consumption by future agents.

## Agent-First Development
* Documentation should be readable by humans, but optimized for consumption by AI agents.
* Tools used should support agent interaction (such as MCP integration).
* In cases where a frequently used tool does not support smooth agent interaction, an interaction layer should be created. This can be a separate task.
* Code should be written with AI agents in mind, without compromising readability and editability for humans.
* In projects with components/tasks that are physical or otherwise inaccessible to AI agents, provide clear instructions or documentation for completion of the task by a human. Ensure bidirectional communication and that assumptions are checked.
* Avoid including code in design documents. Including code in design documents is detrimental for several reasons relating to redundancy:
  - Double maintenance load for maintaining parity.
  - Increase context usage with duplicate information.
  - Locks in implementing agent into a specific path, instead of allowing flexibility.
  - Hinders readability of design documents.

## Design Documents
* Design documents live in `agent/design/`.
* Each design document should describe one system or feature area.
* Design documents must specify: purpose, data structures, public API surface, behavior contracts, and error handling.
* Reference `agent/project.md` for high-level requirements and feature descriptions.
* Reference `example_input/` for sample data files that inform parser/serializer design.
* Do not duplicate information already in `agent/project.md`; link to it instead.

## Implementation Workflow
* Before implementing, read the relevant design document(s) in `agent/design/`.
* Read `agent/technology-stack.md` and `agent/technology-decisions.md` for technology constraints.
* Read `agent/project-structure.md` to understand where new code should be placed.
* Implement one logical unit at a time; each unit must include its tests.
* After implementation, run the build and full test suite before committing.
* When a design document is ambiguous, prefer the simplest interpretation that satisfies `agent/project.md` requirements.

## Style
* Use spaces for indentation. Indentation width is 2 spaces.
* For a given language, determine style as follows:
  1. If present, the style guide document at `agent/style/<language>.md` takes precedence.
  2. Officially recommended/adopted style decisions, such as PEP8 for Python and CamelCase naming for C#.
  3. The most common or widely accepted style guide for the language.
* Set up automated linting to enforce style rules.

## Project Structure
* Refer to `agent/project-structure.md` for project structure details.
* When making persistent decisions about or changes to project structure, record the decision in `agent/project-structure-decisions.md` for consumption by future agents.

## Code Structure
* Strongly prefer small, iterative code changes.
* Create minimally committable changes:
  - One logical unit, system, or bugfix.
  - Tests for the logical unit.
  - Change conforms to the Definition of Done.
* Keep function/method length under 50 lines where possible.
* Each function/method in non-test code must have a documentation comment.
* Use ES module imports/exports exclusively (no CommonJS).
* Export pure functions and classes; avoid module-level side effects.

## Progress Checkpoints
* Create an intermediate commit for every minimally committable change.
* Each commit's description should start with "[Agent]".
* Each commit message should clearly describe the change made.
* Each commit must meet the Definition of Done below.

## Definition of Done
* The project must build successfully.
* All feature code must have unit test coverage of at least 80%.
* All code must conform to relevant style guides and pass lint checks.
* Each system and/or logical block must have integration tests covering 100% of its API surface.
* Each feature and/or user story must have end-to-end tests covering all acceptance criteria.
* Each code change must be verified by running a build and running all tests.

## Before Committing
* Run the command to build the project.
* Run all tests and ensure they pass.

## Build & Test Commands
* Build: `npm run build`
* Lint: `npm run lint`
* Unit/integration tests: `npm test`
* E2E tests: `npm run test:e2e`
* All checks: `npm run check` (lint + test + build)