---
title: Especificadores de substituição (C + + c++ /CLI e c++ /CLI CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- override specifiers, C++
- override specifiers
ms.assetid: 155bbf6f-4722-4654-afb1-9cb52af799fb
ms.openlocfilehash: 9d839b9530cff144cda7897b0c96af48c14454a6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50639845"
---
# <a name="override-specifiers--ccli-and-ccx"></a>Especificadores de substituição (C + + c++ /CLI e c++ /CLI CX)

*Especificadores de substituição* modificar herdados como tipos e membros de tipos herdados se comportam em tipos derivados.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

### <a name="remarks"></a>Comentários

Para obter mais informações sobre especificadores de substituição, consulte:

- [abstract](../windows/abstract-cpp-component-extensions.md)

- [novo (novo slot em vtable)](../windows/new-new-slot-in-vtable-cpp-component-extensions.md)

- [override](../windows/override-cpp-component-extensions.md)

- [sealed](../windows/sealed-cpp-component-extensions.md)

- [Especificadores de substituição e compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md)

**abstrato** e **lacrado** também são válidos em declarações de tipo, onde não atuam como especificadores de substituição.

Para obter informações sobre como substituir explicitamente funções de classe base, consulte [substituições explícitas](../windows/explicit-overrides-cpp-component-extensions.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

(Não há nenhum comentário sobre este recurso de linguagem que se aplicam a apenas o tempo de execução do Windows.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

(Não há nenhum comentário sobre este recurso de linguagem que se aplicam a apenas o common language runtime.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)