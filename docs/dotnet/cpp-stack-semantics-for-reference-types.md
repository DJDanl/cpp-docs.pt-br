---
title: Semântica da pilha do C++ para tipos de referência
ms.date: 11/04/2016
helpviewer_keywords:
- reference types, C++ stack semantics for
ms.assetid: 319a1304-f4a4-4079-8b84-01cec847d531
ms.openlocfilehash: 886d0d16d8b81364078db5604ab10d8dcc3fa561
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87197833"
---
# <a name="c-stack-semantics-for-reference-types"></a>Semântica da pilha do C++ para tipos de referência

Antes do Visual Studio 2005, uma instância de um tipo de referência poderia ser criada apenas usando o **`new`** operador, que criou o objeto no heap coletado pelo lixo. No entanto, agora você pode criar uma instância de um tipo de referência usando a mesma sintaxe que você usaria para criar uma instância de um tipo nativo na pilha. Portanto, você não precisa usar [ref New, gcnew](../extensions/ref-new-gcnew-cpp-component-extensions.md) para criar um objeto de um tipo de referência. E quando o objeto sai do escopo, o compilador chama o destruidor do objeto.

## <a name="remarks"></a>Comentários

Quando você cria uma instância de um tipo de referência usando semântica de pilha, o compilador cria internamente a instância no heap coletado pelo lixo (usando **`gcnew`** ).

Quando a assinatura ou o tipo de retorno de uma função inclui uma instância de um tipo de referência por valor, a função será marcada nos metadados como exigindo tratamento especial (com modreq). Atualmente, esse tratamento especial só é fornecido por clientes Visual C++; outros idiomas atualmente não dão suporte ao consumo de funções ou dados que usam tipos de referência criados com semântica de pilha.

Um motivo para usar **`gcnew`** (alocação dinâmica) em vez de semântica de pilha seria se o tipo não tiver um destruidor. Além disso, usar tipos de referência criados com semânticas de pilha em assinaturas de função não seria possível se você quiser que suas funções sejam consumidas por idiomas diferentes de Visual C++.

O compilador não irá gerar um construtor de cópia para um tipo de referência. Portanto, se você definir uma função que usa um tipo de referência por valor na assinatura, deverá definir um construtor de cópia para o tipo de referência. Um construtor de cópia para um tipo de referência tem uma assinatura do seguinte formato: `R(R%){}` .

O compilador não irá gerar um operador de atribuição padrão para um tipo de referência. Um operador de atribuição permite que você crie um objeto usando semânticas de pilha e inicialize-o com um objeto existente criado usando semântica de pilha. Um operador de atribuição para um tipo de referência tem uma assinatura do seguinte formato: `void operator=( R% ){}` .

Se o destruidor do tipo liberar recursos críticos e você usar semântica de pilha para tipos de referência, não será necessário chamar explicitamente o destruidor (ou chamar **`delete`** ). Para obter mais informações sobre destruidores em tipos de referência, consulte [destruidores e finalizadores em como: definir e consumir classes e estruturas (C++/CLI)](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).

Um operador de atribuição gerado pelo compilador seguirá as regras padrão do C++ comuns com as seguintes adições:

- Quaisquer membros de dados não estáticos cujo tipo é um identificador para um tipo de referência serão copiados superficialmente (tratados como um membro de dados não estático cujo tipo é um ponteiro).

- Qualquer membro de dados não estático cujo tipo é um tipo de valor será uma cópia superficial.

- Qualquer membro de dados não estático cujo tipo é uma instância de um tipo de referência invocará uma chamada para o construtor de cópia do tipo de referência.

O compilador também fornece um `%` operador unário para converter uma instância de um tipo de referência criado usando semântica de pilha para seu tipo de identificador subjacente.

Os seguintes tipos de referência não estão disponíveis para uso com semântica de pilha:

- [delegate (Extensões de componentes do C++)](../extensions/delegate-cpp-component-extensions.md)

- [matrizes](../extensions/arrays-cpp-component-extensions.md)

- <xref:System.String>

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O exemplo de código a seguir mostra como declarar instâncias de tipos de referência com semântica de pilha, como o operador de atribuição e o construtor de cópia funcionam e como inicializar uma referência de rastreamento com o tipo de referência criado usando semânticas de pilha.

### <a name="code"></a>Código

```cpp
// stack_semantics_for_reference_types.cpp
// compile with: /clr
ref class R {
public:
   int i;
   R(){}

   // assignment operator
   void operator=(R% r) {
      i = r.i;
   }

   // copy constructor
   R(R% r) : i(r.i) {}
};

void Test(R r) {}   // requires copy constructor

int main() {
   R r1;
   r1.i = 98;

   R r2(r1);   // requires copy constructor
   System::Console::WriteLine(r1.i);
   System::Console::WriteLine(r2.i);

   // use % unary operator to convert instance using stack semantics
   // to its underlying handle
   R ^ r3 = %r1;
   System::Console::WriteLine(r3->i);

   Test(r1);

   R r4;
   R r5;
   r5.i = 13;
   r4 = r5;   // requires a user-defined assignment operator
   System::Console::WriteLine(r4.i);

   // initialize tracking reference
   R % r6 = r4;
   System::Console::WriteLine(r6.i);
}
```

### <a name="output"></a>Saída

```Output
98
98
98
13
13
```

## <a name="see-also"></a>Confira também

[Classes e structs](../extensions/classes-and-structs-cpp-component-extensions.md)
