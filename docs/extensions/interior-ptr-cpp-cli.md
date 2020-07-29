---
title: interior_ptr (C++/CLI)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- stdcli::language::interior_ptr
- interior_ptr_cpp
- interior_ptr
helpviewer_keywords:
- interior_ptr keyword [C++]
ms.assetid: 25160f74-569e-492d-9e3c-67ece7486baa
ms.openlocfilehash: affec6dcd88290b24a92cd9035a131baee38bcf1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214263"
---
# <a name="interior_ptr-ccli"></a>interior_ptr (C++/CLI)

Um *ponteiro interno* declara um ponteiro para dentro de um tipo de referência, mas não para o objeto propriamente dito. Um ponteiro interno pode apontar para um identificador de referência, um tipo de valor, um identificador de tipo com conversão boxing, um membro de um tipo gerenciado ou um elemento de uma matriz gerenciada.

## <a name="all-runtimes"></a>Todos os Runtimes

(Não há comentários para esse recurso de linguagem que se apliquem a todos os runtimes.)

## <a name="windows-runtime"></a>Windows Runtime

(Não há comentários para esse recurso de linguagem que se apliquem somente ao Windows Runtime.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

O exemplo de sintaxe a seguir demonstra um ponteiro interno.

### <a name="syntax"></a>Sintaxe

```cpp
cli::interior_ptr<cv_qualifier type> var = &initializer;
```

### <a name="parameters"></a>parâmetros

*cv_qualifier*<br/>
**`const`** ou **`volatile`** qualificadores.

*tipo*<br/>
O tipo de *inicializador*.

*var*<br/>
O nome da variável **interior_ptr**.

*initializer*<br/>
Um membro de um tipo de referência, um elemento de uma matriz gerenciada ou qualquer outro objeto que você possa atribuir a um ponteiro nativo.

### <a name="remarks"></a>Comentários

Um ponteiro nativo não é capaz de rastrear um item enquanto sua localização é alterada no heap gerenciado, o que é resultante da movimentação de instâncias de um objeto pelo coletor de lixo. Para que um ponteiro faça referência à instância corretamente, o runtime precisa atualizá-lo para o objeto recém-posicionado.

Um **interior_ptr** representa um superconjunto da funcionalidade de um ponteiro nativo.  Portanto, qualquer coisa que possa ser atribuída a um ponteiro nativo também pode ser atribuída a um **interior_ptr**.  Um ponteiro interno tem permissão para realizar o mesmo conjunto de operações que os ponteiros nativos, incluindo comparação e aritmética de ponteiros.

Um ponteiro interno só pode ser declarado na pilha.  Um ponteiro interno não pode ser declarado como membro de uma classe.

Como ponteiros internos existem somente na pilha, a opção de obter o endereço de um ponteiro interno produz um ponteiro não gerenciado.

**interior_ptr** tem uma conversão implícita para **`bool`** , que permite seu uso em instruções condicionais.

Confira em [pin_ptr](pin-ptr-cpp-cli.md) mais informações sobre como declarar um ponteiro interno que aponta para um objeto que não pode ser movido no heap obtido pelo coletor de lixo.

**interior_ptr** está no namespace cli.  Saiba mais em [Namespaces da CLI, de plataforma e padrão](platform-default-and-cli-namespaces-cpp-component-extensions.md).

Confira mais informações sobre ponteiros internos em

- [Como declarar e usar ponteiros internos e matrizes gerenciadas (C++/CLI)](how-to-declare-and-use-interior-pointers-and-managed-arrays-cpp-cli.md)

- [Como declarar tipos de valor com a palavra-chave interior_ptr (C++/CLI)](how-to-declare-value-types-with-the-interior-ptr-keyword-cpp-cli.md)

- [Como sobrecarregar funções com ponteiros internos e nativos (C++/CLI)](how-to-overload-functions-with-interior-pointers-and-native-pointers-cpp-cli.md)

- [Como declarar ponteiros internos com a palavra-chave const (C++/CLI)](how-to-declare-interior-pointers-with-the-const-keyword-cpp-cli.md)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo a seguir mostra como declarar e usar um ponteiro interno em um tipo de referência.

```cpp
// interior_ptr.cpp
// compile with: /clr
using namespace System;

ref class MyClass {
public:
   int data;
};

int main() {
   MyClass ^ h_MyClass = gcnew MyClass;
   h_MyClass->data = 1;
   Console::WriteLine(h_MyClass->data);

   interior_ptr<int> p = &(h_MyClass->data);
   *p = 2;
   Console::WriteLine(h_MyClass->data);

   // alternatively
   interior_ptr<MyClass ^> p2 = &h_MyClass;
   (*p2)->data = 3;
   Console::WriteLine((*p2)->data);
}
```

```Output
1
2
3
```

## <a name="see-also"></a>Confira também

[Extensões de componente para .NET e UWP](component-extensions-for-runtime-platforms.md)
