---
title: interior_ptr (C++ /CLI CLI) | Microsoft Docs
ms.custom: ''
ms.date: 10/12/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- stdcli::language::interior_ptr
- interior_ptr_cpp
- interior_ptr
dev_langs:
- C++
helpviewer_keywords:
- interior_ptr keyword [C++]
ms.assetid: 25160f74-569e-492d-9e3c-67ece7486baa
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d47539c9d7d8e51a061aba35e6b2f3b8f7049951
ms.sourcegitcommit: 3f4e92266737ecb70507871e87dc8e2965ad7e04
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/15/2018
ms.locfileid: "49328045"
---
# <a name="interiorptr-ccli"></a>interior_ptr (C++/CLI)

Uma *ponteiro interior* declara um ponteiro para dentro de um tipo de referência, mas não ao próprio objeto. Um ponteiro interior pode apontar para um identificador de referência, o tipo de valor, o identificador de tipo demarcado, o membro de um tipo gerenciado, ou a um elemento de uma matriz gerenciada.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

(Não há nenhum comentário sobre este recurso de linguagem que se aplicam a todos os tempos de execução.)

## <a name="windows-runtime"></a>Tempo de Execução do Windows

(Não há nenhum comentário sobre este recurso de linguagem que se aplicam a apenas o tempo de execução do Windows.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

O exemplo de sintaxe a seguir demonstra um ponteiro interior.

### <a name="syntax"></a>Sintaxe

```cpp
cli::interior_ptr<cv_qualifier type> var = &initializer;
```

### <a name="parameters"></a>Parâmetros

*cv_qualifier*<br/>
**Const** ou **volátil** qualificadores.

*type*<br/>
O tipo de *inicializador*.

*var*<br/>
O nome da **interior_ptr** variável.

*initializer*<br/>
Um membro de um tipo de referência, o elemento de uma matriz gerenciada ou qualquer outro objeto que você pode atribuir a um ponteiro nativo.

### <a name="remarks"></a>Comentários

Um ponteiro nativo não é capaz de rastrear um item como as alterações de sua localização no heap gerenciado, o que resulta do coletor de lixo mover instâncias de um objeto. Para um ponteiro referir-se à instância corretamente, o tempo de execução precisa atualizar o ponteiro para o objeto recentemente posicionado.

Uma **interior_ptr** representa um superconjunto da funcionalidade de um ponteiro nativo.  Portanto, tudo o que pode ser atribuído a um ponteiro nativo também pode ser atribuído a um **interior_ptr**.  Um ponteiro interior tem permissão para executar o mesmo conjunto de operações como ponteiros nativos, incluindo a comparação e aritmética de ponteiro.

Um ponteiro interior só pode ser declarado na pilha.  Um ponteiro interior não pode ser declarado como um membro de uma classe.

Como ponteiros internos existem apenas na pilha, tomar o endereço de um ponteiro interior produz um ponteiro não gerenciado.

**interior_ptr** tem uma conversão implícita **bool**, que permite seu uso em instruções condicionais.

Para obter informações sobre como declarar um ponteiro interior que aponta para um objeto que não pode ser movido no heap coletado como lixo, consulte [pin_ptr](../windows/pin-ptr-cpp-cli.md).

**interior_ptr** está no namespace cli.  Ver [plataforma, padrão e cli Namespaces](../windows/platform-default-and-cli-namespaces-cpp-component-extensions.md) para obter mais informações.

Para obter mais informações sobre ponteiros internos, consulte

- [Como declarar e usar ponteiros internos e matrizes gerenciadas (C++/CLI)](../windows/how-to-declare-and-use-interior-pointers-and-managed-arrays-cpp-cli.md)

- [Como declarar tipos de valor com a palavra-chave interior_ptr (C++/CLI)](../windows/how-to-declare-value-types-with-the-interior-ptr-keyword-cpp-cli.md)

- [Como sobrecarregar funções com ponteiros internos e nativos (C++/CLI)](../windows/how-to-overload-functions-with-interior-pointers-and-native-pointers-cpp-cli.md)

- [Como declarar ponteiros internos com a palavra-chave const (C++/CLI)](../windows/how-to-declare-interior-pointers-with-the-const-keyword-cpp-cli.md)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo a seguir mostra como declarar e usar um ponteiro interior em um tipo de referência.

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

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)