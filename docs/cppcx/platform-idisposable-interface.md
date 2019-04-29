---
title: Interface Platform::IDisposable
ms.date: 02/03/2017
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::IDisposable
helpviewer_keywords:
- Platform::IDisposable Interface
ms.assetid: f4344056-7030-42ed-bc98-b140edffddcd
ms.openlocfilehash: f114959321c0ed3879a089b944a5ff1b19843118
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62257823"
---
# <a name="platformidisposable-interface"></a>Interface Platform::IDisposable

Usada para liberar recursos não gerenciados.

## <a name="syntax"></a>Sintaxe

```cpp
public interface class IDisposable
```

## <a name="attributes"></a>Atributos

**GuidAttribute**("de0cbaea-8065-4a45-b196-c9d443f9bab3")

**VersionAttribute**(NTDDI_WIN8)

### <a name="members"></a>Membros

A interface IDisposable herda da interface IUnknown. IDisposable também tem os seguintes tipos de membros:

**Métodos**

A interface IDisposable tem os métodos descritos a seguir.

|Método|Descrição|
|------------|-----------------|
|Dispose|Usada para liberar recursos não gerenciados.|

### <a name="requirements"></a>Requisitos

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Plataforma