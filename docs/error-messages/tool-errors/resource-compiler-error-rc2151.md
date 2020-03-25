---
title: Erro RC2151 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC2151
helpviewer_keywords:
- RC2151
ms.assetid: 3c47e535-c78d-4338-aab9-9b47e2c34728
ms.openlocfilehash: 9d4eea92321ca8373f3ad5f121f4a8e96d878e79
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80191256"
---
# <a name="resource-compiler-error-rc2151"></a>Erro RC2151 (compilador de recurso)

Não é possível usar novamente as constantes de cadeia de caracteres

Você está usando o mesmo valor duas vezes em uma instrução **STRINGTABLE** . Verifique se você não está misturando valores decimais e hexadecimais sobrepostos.

Cada ID em um **STRINGTABLE** deve ser exclusivo. Para obter máxima eficiência, use constantes contíguas que começam em um múltiplo de 16.
