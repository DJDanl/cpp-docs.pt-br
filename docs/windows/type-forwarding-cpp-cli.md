---
title: Encaminhamento de tipo (C + + / CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- type forwarding, C++
ms.assetid: ae730b69-0c27-41cc-84e1-3132783866ea
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 806003e33e60b5146bdd722fa5248011cd4939c0
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46396539"
---
# <a name="type-forwarding-ccli"></a>Encaminhamento de tipos (C++/CLI)

*Encaminhamento de tipo* permite que você mova um tipo de um assembly (assembly A) em outro assembly (assembly B), de modo que não é necessário recompilar os clientes que consomem o assembly A.

## <a name="all-platforms"></a>Todas as Plataformas

Não há suporte para esse recurso em todos os tempos de execução.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

Não há suporte para esse recurso no tempo de execução do Windows.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

O exemplo de código a seguir demonstra como usar o encaminhamento de tipo.

### <a name="syntax"></a>Sintaxe

```
#using "new.dll"
[assembly:TypeForwardedTo(type::typeid)];
```

### <a name="parameters"></a>Parâmetros

*new*<br/>
O assembly no qual você está movendo a definição de tipo.

*type*<br/>
O tipo cuja definição que você está movendo em outro assembly.

### <a name="remarks"></a>Comentários

Depois que um componente (assembly) é fornecido e estiver sendo usado por aplicativos cliente, você pode usar tipo de encaminhamento para mover um tipo de componente (assembly) em outro assembly, envie o componente de atualização (e todos os assemblies adicionais necessários) e o cliente aplicativos ainda funcionará sem que está sendo recompilado.

Encaminhamento de tipo só funciona para componentes referenciados pelos aplicativos existentes. Quando você recria um aplicativo, deve haver as referências de assembly apropriados para alguns tipos usados no aplicativo.

Ao encaminhar um tipo (tipo A) de um assembly, você deve adicionar o `TypeForwardedTo` atributo para esse tipo, bem como uma referência de assembly. O assembly que você faz referência deve conter um dos seguintes:

- A definição de tipo a.

- Um `TypeForwardedTo` atributo para um tipo, bem como uma referência de assembly.

Exemplos de tipos que podem ser encaminhados:

- classes de referência

- classes de valor

- enums

- interfaces

Você não pode encaminhar os seguintes tipos:

- Tipos genéricos

- Tipos nativos

- Tipos aninhados (se você quiser encaminhar um tipo aninhado, você deve encaminhar o tipo delimitador)

Você pode encaminhar um tipo para um assembly criado em qualquer linguagem para o common language runtime.

Portanto, se um arquivo de código fonte que é usado para compilar o assembly. dll contém uma definição de tipo (`ref class MyClass`), e você desejar mover esse tipo de definição para o assembly b. dll, seria:

1. Mover o `MyClass` definição para um arquivo de código de origem usado para criar o b. dll de tipo.

2. Compilar o assembly b. dll

3. Excluir o `MyClass` tipo de definição do código-fonte usado para compilar a dll e substituí-lo com o seguinte:

    ```
    #using "B.dll"
    [assembly:TypeForwardedTo(MyClass::typeid)];
    ```

4. Compile o assembly. dll.

5. Use o DLL sem recompilar os aplicativos cliente.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`