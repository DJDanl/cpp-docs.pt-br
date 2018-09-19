---
title: Erro de Build prj0013 do projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0013
dev_langs:
- C++
helpviewer_keywords:
- PRJ0013
ms.assetid: 95e7bafd-63c8-4b2d-b778-f19cdf9ba36c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f7a151ca34d680a517c405e5cb6f91c18d35bedd
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46102639"
---
# <a name="project-build-error-prj0013"></a>Erro de Build PRJ0013 no Projeto

Os recursos do sistema podem ficar baixos de maneira crítica. Não foi possível criar um pipe necessário para lançar uma compilação.

Esse erro indica que os recursos do sistema estão baixos. Para resolver esse erro, reduza o uso dos recursos do sistema por parte de outros processos/aplicativos.

Esse erro também pode ocorrer se o nível de segurança não é suficiente para criar pipes (consulte [CreatePipe](https://msdn.microsoft.com/library/windows/desktop/aa365152.aspx)).