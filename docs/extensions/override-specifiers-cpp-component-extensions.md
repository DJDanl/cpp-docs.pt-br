---
title: Especificadores de substituição (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- override specifiers, C++
- override specifiers
ms.assetid: 155bbf6f-4722-4654-afb1-9cb52af799fb
ms.openlocfilehash: c1e8e7db2879b0226eaff562f5b5b826bce14caf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65515741"
---
# <a name="override-specifiers--ccli-and-ccx"></a>Especificadores de substituição (C++/CLI e C++/CX)

Os *Especificadores de substituição* modificam a forma como os tipos herdados e os membros de tipos herdados se comportam em tipos derivados.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

### <a name="remarks"></a>Comentários

Confira mais informações sobre especificadores de substituição em:

- [abstract](abstract-cpp-component-extensions.md)

- [novo (novo slot em vtable)](new-new-slot-in-vtable-cpp-component-extensions.md)

- [override](override-cpp-component-extensions.md)

- [sealed](sealed-cpp-component-extensions.md)

- [Especificadores de substituição e compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md)

**abstract** e **sealed** também são válidos em declarações de tipo, nas quais eles não atuam como especificadores de substituição.

Confira mais informações sobre como substituir funções de classe base explicitamente em [Substituições explícitas](explicit-overrides-cpp-component-extensions.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

(Não há comentários para esse recurso de linguagem que se apliquem somente ao Windows Runtime.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

(Não há comentários para esse recurso de linguagem que se apliquem apenas ao Common Language Runtime.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)