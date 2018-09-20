---
title: 'Método Module:: unregistercomobject | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::UnregisterCOMObject
dev_langs:
- C++
helpviewer_keywords:
- UnregisterCOMObject method
ms.assetid: 5d377525-0385-482a-a215-6e8a1f032861
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 46450142c0455dd4eb96f627abd077e478d96fea
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46383500"
---
# <a name="moduleunregistercomobject-method"></a>Método Module::UnregisterCOMObject

Cancela o registro de um ou mais objetos COM, que impede que outros aplicativos se conectem a eles.

## <a name="syntax"></a>Sintaxe

```cpp
virtual HRESULT UnregisterCOMObject(
   const wchar_t* serverName,
   DWORD* cookies,
   unsigned int count
```

### <a name="parameters"></a>Parâmetros

*ServerName*<br/>
(Não usado)

*Cookies*<br/>
Uma matriz de ponteiros para valores que identificam os objetos de classe para cancelar o registro. A matriz foi criada por meio de [RegisterCOMObject](../windows/module-registercomobject-method.md) método.

*count*<br/>
O número de classes para cancelar o registro.

## <a name="return-value"></a>Valor de retorno

S_OK se essa operação for bem-sucedida; Caso contrário, um erro HRESULT que indica o motivo pelo qual a operação falhou.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe Module](../windows/module-class.md)