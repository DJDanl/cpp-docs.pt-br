---
title: Interface Platform::IDisposable
ms.date: 02/03/2017
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::IDisposable
helpviewer_keywords:
- Platform::IDisposable Interface
ms.assetid: f4344056-7030-42ed-bc98-b140edffddcd
ms.openlocfilehash: 0024edbad0bb3311a0497be67fc8bcfc954602e1
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214234"
---
# <a name="platformidisposable-interface"></a>Interface Platform::IDisposable

Usada para liberar recursos não gerenciados.

## <a name="syntax"></a>Sintaxe

```cpp
public interface class IDisposable
```

## <a name="attributes"></a>Atributos

**GuidAttribute**("de0cbaea-8065-4a45-b196-c9d443f9bab3")

**Versãoattribute**(NTDDI_WIN8)

### <a name="members"></a>Membros

A interface IDisposable herda da interface IUnknown. IDisposable também tem os seguintes tipos de membros:

**Métodos**

A interface IDisposable tem os métodos descritos a seguir.

|Método|DESCRIÇÃO|
|------------|-----------------|
|Dispose|Usada para liberar recursos não gerenciados.|

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Platform
