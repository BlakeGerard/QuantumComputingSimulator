/*
        Title: q_circuit_gates.cpp
        Author: Blake Gerard
        Date: 05/16/2020
        Description: Allow the user to apply supported gates to specified
        qubits in a q_circuit.
*/

#include "q_circuit.h"
#include "gate_matrices.h"
#include "gate_enum.h"

/*
    Apply the Hadamard gate to a single qubit.

    Params:
        qubit_index: Register index of the target qubit
    Return:
        None
*/
void Q_Circuit::H(int qubit_index) {
    if (!state.isZero()) {
        apply_single_qubit_gate(qubit_index, gate_matrices[Gate::H]);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the Hadamard gate to a set of qubits.

    Params:
        qubit_indices: List of register indices of the target qubits
    Return:
        None
*/
void Q_Circuit::H(std::vector<int> qubit_indices) {
    if (!state.isZero()) {   
        apply_single_qubit_gate(qubit_indices, gate_matrices[Gate::H]);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the Pauli-X gate to a single qubit.

    Params:
        qubit_index: Register index of the target qubit
    Return:
        None
*/
void Q_Circuit::X(int qubit_index) {
    if (!state.isZero()) {
        apply_single_qubit_gate(qubit_index, gate_matrices[Gate::X]);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the Pauli-X gate to a set of qubits.

    Params:
        qubit_indices: List of register indices of the target qubits
    Return:
        None
*/
void Q_Circuit::X(std::vector<int> qubit_indices) {
    if (!state.isZero()) {
        apply_single_qubit_gate(qubit_indices, gate_matrices[Gate::X]);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the Pauli-Y gate to a single qubit.

    Params:
        qubit_index: Register index of the target qubit
    Return:
        None
*/
void Q_Circuit::Y(int qubit_index) {
    if (!state.isZero()) {
        apply_single_qubit_gate(qubit_index, gate_matrices[Gate::Y]);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the Pauli-Y gate to a set of qubits.

    Params:
        qubit_indices: List of register indices of the target qubits
    Return:
        None
*/
void Q_Circuit::Y(std::vector<int> qubit_indices) {
    if (!state.isZero()) {
        apply_single_qubit_gate(qubit_indices, gate_matrices[Gate::Y]);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the Pauli-Z gate to a single qubit.

    Params:
        qubit_index: Register index of the target qubit
    Return:
        None
*/
void Q_Circuit::Z(int qubit_index) {
    if (!state.isZero()) {
        apply_single_qubit_gate(qubit_index, gate_matrices[Gate::Z]);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the Pauli-Z gate to a set of qubits.

    Params:
        qubit_indices: List of register indices of the target qubits
    Return:
        None
*/
void Q_Circuit::Z(std::vector<int> qubit_indices) {
    if (!state.isZero()) {
        apply_single_qubit_gate(qubit_indices, gate_matrices[Gate::Z]);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }   
}

/*
    Apply the Phase (R_phi) gate to a single qubit.

    Params:
        phi: Phase shift in radians
        qubit_index: Register index of the target qubit
        dagger: Force hermitian conjugate
    Return:
        None
*/
void Q_Circuit::R(double phi, int qubit_index, int dagger /*=0*/) {
    if (!state.isZero()) {
        Eigen::Matrix2cd gate;
        gate << 1.0, 0.0, 0.0, exp(std::complex<double>(0.0, 1.0) * phi);
        if (dagger) {gate.adjointInPlace();}
        apply_single_qubit_gate(qubit_index, gate);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }   
}

/*
    Apply the Phase (R_phi) gate to a set of qubits.

    Params:
        phi: Phase shift in radians
        qubit_indices: List of register indices of the target qubits
        dagger: Force hermitian conjugate
    Return:
        None
*/
void Q_Circuit::R(double phi, std::vector<int> qubit_indices, int dagger /*=0*/) {
    if (!state.isZero()) {
        Eigen::Matrix2cd gate;
        gate << 1.0, 0.0, 0.0, exp(std::complex<double>(0.0, 1.0) * phi);
        if (dagger) {gate.adjointInPlace();}
        apply_single_qubit_gate(qubit_indices, gate);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the S gate to a single qubit.

    Params:
        qubit_index: Register index of the target qubit
        dagger: Force hermitian conjugate
    Return:
        None
*/
void Q_Circuit::S(int qubit_index, int dagger) {
    if (!state.isZero()) {
        if (dagger) { apply_single_qubit_gate(qubit_index, gate_matrices[Gate::S].adjoint()); }
        else        { apply_single_qubit_gate(qubit_index, gate_matrices[Gate::S]); }
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the S gate to a set of qubits.

    Params:
        qubit_indices: List of register indices of the target qubits
        dagger: Force hermitian conjugate
    Return:
        None
*/
void Q_Circuit::S(std::vector<int> qubit_indices, int dagger) {
    if (!state.isZero()) {
        if (dagger) { apply_single_qubit_gate(qubit_indices, gate_matrices[Gate::S].adjoint()); }
        else        { apply_single_qubit_gate(qubit_indices, gate_matrices[Gate::S]); }
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the T gate to a single qubit.

    Params:
        qubit_index: Register index of the target qubit
        dagger: Force hermitian conjugate
    Return:
        None
*/
void Q_Circuit::T(int qubit_index, int dagger) {
    if (!state.isZero()) {
        if (dagger) { apply_single_qubit_gate(qubit_index, gate_matrices[Gate::T].adjoint()); }
        else        { apply_single_qubit_gate(qubit_index, gate_matrices[Gate::T]); }
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the T gate to a set of qubits.

    Params:
        qubit_indices: List of register indices of the target qubits
        dagger: Force hermitian conjugate
    Return:
        None
*/
void Q_Circuit::T(std::vector<int> qubit_indices, int dagger) {
    if (!state.isZero()) {
        if (dagger) { apply_single_qubit_gate(qubit_indices, gate_matrices[Gate::T].adjoint()); }
        else        { apply_single_qubit_gate(qubit_indices, gate_matrices[Gate::T]); }
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the IBM U3 gate to a single qubit.
    https://arxiv.org/pdf/1707.03429.pdf, p. 5

    Params:
        theta: U3 parameter
        phi: U3 parameter
        lambda: U3 parameter
        qubit_index: Register index of the target qubit
        dagger: Force hermitian conjugate
    Return:
        None
*/
void Q_Circuit::U3(double theta, double phi, double lambda, int qubit_index, int dagger) {
    if (!state.isZero()) {
        Eigen::Matrix2cd gate;
        std::complex<double> me_i{0.0, 1.0};
        gate << exp((-me_i * (phi+lambda)) / 2.0) * cos(theta/2.0), -exp((-me_i * (phi-lambda)) / 2.0) * sin(theta/2.0),
                exp((me_i * (phi-lambda)) / 2.0) * sin(theta/2.0), exp((me_i * (phi+lambda)) / 2.0) * cos(theta/2.0);
        if (dagger) {gate.adjointInPlace();}
        apply_single_qubit_gate(qubit_index, gate);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the IBM U3 gate to a set of qubit.
    https://arxiv.org/pdf/1707.03429.pdf, p. 5

    Params:
        theta: U3 parameter
        phi: U3 parameter
        lambda: U3 parameter
        qubit_indices: List of register indices of the target qubits
        dagger: Force hermitian conjugate
    Return:
        None
*/
void Q_Circuit::U3(double theta, double phi, double lambda, std::vector<int> qubit_indices, int dagger) {
    if (!state.isZero()) {
        Eigen::Matrix2cd gate;
        std::complex<double> me_i{0.0, 1.0};
        gate << exp((-me_i * (phi+lambda)) / 2.0) * cos(theta/2.0), -exp((-me_i * (phi-lambda)) / 2.0) * sin(theta/2.0),
                exp((me_i * (phi-lambda)) / 2.0) * sin(theta/2.0), exp((me_i * (phi+lambda)) / 2.0) * cos(theta/2.0);
        if (dagger) {gate.adjointInPlace();}
        apply_single_qubit_gate(qubit_indices, gate);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the CNOT gate to control and target qubits.

    Params:
        control: Register index of the control qubit
        target: Register index of the target qubit
    Return:
        None
*/
void Q_Circuit::CNOT(int control, int target) {
    if (!state.isZero()) {
        apply_controlled_single_qubit_gate(control, target, gate_matrices[Gate::X]);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the CY gate to control and target qubits.

    Params:
        control: Register index of the control qubit
        target: Register index of the target qubit
    Return:
        None
*/
void Q_Circuit::CY(int control, int target) {
    if (!state.isZero()) {
        apply_controlled_single_qubit_gate(control, target, gate_matrices[Gate::Y]);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the CZ gate to control and target qubits.

    Params:
        control: Register index of the control qubit
        target: Register index of the target qubit
    Return:
        None
*/
void Q_Circuit::CZ(int control, int target) {
    if (!state.isZero()) {
        apply_controlled_single_qubit_gate(control, target, gate_matrices[Gate::Z]);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the CR gate to control and target qubits.

    Params:
        phi: Phase shift in radians
        control: Register index of the control qubit
        target: Register index of the target qubit
    Return:
        None
*/
void Q_Circuit::CR(double phi, int control, int target) {
    if (!state.isZero()) {
        Eigen::Matrix2cd gate;
        gate << 1.0, 0.0, 0.0, exp(std::complex<double>(0.0, 1.0) * phi);
        apply_controlled_single_qubit_gate(control, target, gate);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the SWAP gate to swap two qubits.

    Params:
        qubit1: Register index of the first qubit
        qubit2: Register index of the second qubit
    Return:
        None
*/
void Q_Circuit::SWAP(int qubit1, int qubit2) {
    if (!state.isZero()) {
        apply_swap_gate(qubit1, qubit2, gate_matrices[Gate::SWAP]);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}

/*
    Apply the CCNOT gate to two controls and one target qubit.

    Params:
        control1: Register index of the first control qubit
        control2: Register index of the second control qubit
        target: Register index of the target qubit
    Return:
        None
*/
void Q_Circuit::CCNOT(int control1, int control2, int target) {
    if (!state.isZero()) {
        apply_controlled_two_qubit_gate(control1, control2, target, gate_matrices[Gate::X]);
    } else {
        throw "Must initialize qubits before calling gate operations.";
    }
}