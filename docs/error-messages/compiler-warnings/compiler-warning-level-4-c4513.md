---
title: Compilador aviso (nível 4) C4513
ms.date: 11/04/2016
f1_keywords:
- C4513
helpviewer_keywords:
- C4513
ms.assetid: 6877334a-f30a-4184-9483-dac3348737a4
ms.openlocfilehash: cbde035a988e5f6ac64303b2ed159b885ece8684
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62221057"
---
# <a name="compiler-warning-level-4-c4513"></a>Compilador aviso (nível 4) C4513

'class': não foi possível gerar um destruidor

O compilador não gere um destruidor de padrão de uma determinada classe; Nenhum destruidor foi criado. O destruidor está em uma classe base que não está acessível para a classe derivada. Se a classe base tem um destruidor privado, torne-o público ou protegido.