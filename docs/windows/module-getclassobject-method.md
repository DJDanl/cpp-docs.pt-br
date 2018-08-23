---
title: 'Método Module:: GetClassObject | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::GetClassObject
dev_langs:
- C++
helpviewer_keywords:
- GetClassObject method
ms.assetid: 95b0de1b-f728-4f96-9f44-f6ea71ce56e4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3e0c8996823de35bbfd85d595556db933f34238a
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42599216"
---
# <a name="modulegetclassobject-method"></a>Método Module::GetClassObject

Recupera um cache de fábricas de classes.

## <a name="syntax"></a>Sintaxe

```cpp
 HRESULT GetClassObject(
   REFCLSID clsid,
   REFIID riid,
   _Deref_out_ void **ppv,
   wchar_t* serverName = nullptr
);
```

### <a name="parameters"></a>Parâmetros

*clsid*  
ID de classe.

*riid*  
ID de interface que você solicitar.

*ppv*  
Ponteiro para o objeto retornado.

*ServerName*  
O nome do servidor que é especificado em ambos os `ActivatableClassWithFactory`, `ActivatableClassWithFactoryEx`, ou `ActivatableClass` macro; ou **nullptr** para obter o nome do servidor padrão.

## <a name="return-value"></a>Valor de retorno

## <a name="remarks"></a>Comentários

Use esse método somente para COM, não o tempo de execução do Windows. Esse método expõe apenas `IClassFactory` métodos.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também
[Classe Module](../windows/module-class.md)