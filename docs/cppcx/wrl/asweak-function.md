---
title: Função AsWeak
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::AsWeak
helpviewer_keywords:
- AsWeak function
ms.assetid: a6f10cfc-c1d6-4761-adb9-1a119cc99913
ms.openlocfilehash: 45df6332fccb2a22284eb6478c7554d87318ca78
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62398843"
---
# <a name="asweak-function"></a>Função AsWeak

Recupera uma referência fraca a uma instância especificada.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
HRESULT AsWeak(
   _In_ T* p,
   _Out_ WeakRef* pWeak
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Um ponteiro para o tipo do parâmetro *p*.

*p*<br/>
Uma instância de um tipo.

*pWeak*<br/>
Quando essa operação for concluída, um ponteiro para uma referência fraca ao parâmetro *p*.

## <a name="return-value"></a>Valor de retorno

S_OK, se essa operação for bem-sucedida; Caso contrário, um erro HRESULT que indica a causa da falha.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)