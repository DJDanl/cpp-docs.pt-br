---
title: Encaminhamento de tipos (C++/CLI)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- type forwarding, C++
ms.assetid: ae730b69-0c27-41cc-84e1-3132783866ea
ms.openlocfilehash: 0803ecc2ffb2da2748b1ef063481aa2571f27f50
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80171925"
---
# <a name="type-forwarding-ccli"></a>Encaminhamento de tipos (C++/CLI)

O *encaminhamento de tipo* permite que você mova um tipo de um assembly (assembly A) para outro assembly (assembly B), de modo que não seja necessário compilar novamente os clientes que consomem o assembly A.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

Este recurso não é compatível com o Windows Runtime.

## <a name="common-language-runtime"></a>Common Language Runtime

O exemplo de código a seguir demonstra como usar o encaminhamento de tipo.

### <a name="syntax"></a>Sintaxe

```cpp
#using "new.dll"
[assembly:TypeForwardedTo(type::typeid)];
```

### <a name="parameters"></a>parâmetros

*novo*<br/>
O assembly para o qual você está movendo a definição de tipo.

*tipo*<br/>
O tipo cuja definição você está movendo para outro assembly.

### <a name="remarks"></a>Comentários

Depois que um componente (assembly) é enviado e usado por aplicativos cliente, você pode usar o encaminhamento de tipo para mover um tipo do componente (assembly) para outro assembly, enviar o componente atualizado (e quaisquer assemblies adicionais necessários) e os aplicativos clientes ainda funcionarão sem serem recompilados.

O encaminhamento de tipo funciona apenas para componentes referenciados pelos aplicativos existentes. Quando você recria um aplicativo, deve haver as referências de assembly apropriadas para todos os tipos usados ​​no aplicativo.

Ao encaminhar um tipo (Tipo A) de um assembly, você deve adicionar o atributo `TypeForwardedTo` a esse tipo e uma referência de assembly. O assembly ao qual você faz referência deve conter um dos seguintes:

- A definição do Tipo A.

- Um atributo `TypeForwardedTo` do Tipo A e uma referência de assembly.

Exemplos de tipos que podem ser encaminhados incluem:

- classes ref

- classes de valor

- enums

- interfaces

Você não pode encaminhar os seguintes tipos:

- Tipos genéricos

- Tipos nativos

- Tipos aninhados (se você quer encaminhar um tipo aninhado, deve encaminhar o tipo delimitador)

Você pode encaminhar um tipo para um assembly criado em qualquer linguagem que tenha como destino o Common Language Runtime.

Portanto, se um arquivo de código-fonte usado para compilar o assembly A.dll contiver uma definição de tipo (`ref class MyClass`) e você desejar mover essa definição de tipo para o assembly B.dll, você deverá:

1. Mover a definição do tipo `MyClass` para um arquivo de código-fonte usado para criar B.dll.

2. Compilar o assembly B.dll.

3. Excluir a definição de tipo `MyClass` do código-fonte usado para criar A.dll e substituir pelo seguinte:

    ```cpp
    #using "B.dll"
    [assembly:TypeForwardedTo(MyClass::typeid)];
    ```

4. Compilar o assembly A.dll.

5. Usar A.dll sem recompilar os aplicativos clientes.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`
