---
title: Função TerminateMap
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::TerminateMap
helpviewer_keywords:
- TerminateMap function
ms.assetid: 1c314a61-da5d-49bb-ac44-c34ee3c23b66
ms.openlocfilehash: 2aa4d6733d2a4e458ff8abff192778d52a4522b2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233490"
---
# <a name="terminatemap-function"></a>Função TerminateMap

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
inline bool TerminateMap(
   _In_ ModuleBase *module,
   _In_opt_z_ const wchar_t *serverName,
    bool forceTerminate) throw()
```

### <a name="parameters"></a>parâmetros

*modulo*<br/>
Um [módulo](module-class.md).

*serverName*<br/>
O nome de um subconjunto de fábricas de classe no módulo especificado pelo *módulo*de parâmetro.

*forceTerminate*<br/>
**`true`** para encerrar as fábricas de classe independentemente de estarem ativas; **`false`** para não encerrar as fábricas de classe, se qualquer fábrica estiver ativa.

## <a name="return-value"></a>Valor retornado

**`true`** se todas as fábricas de classe foram encerradas; caso contrário, **`false`** .

## <a name="remarks"></a>Comentários

Desliga as fábricas de classes no módulo especificado.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Module. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="see-also"></a>Confira também

[Namespace Microsoft:: WRL::D etalhes](microsoft-wrl-details-namespace.md)
