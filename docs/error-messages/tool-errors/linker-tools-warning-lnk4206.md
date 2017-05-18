---
title: Aviso LNK4206 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4206
dev_langs:
- C++
helpviewer_keywords:
- LNK4206
ms.assetid: 6c108e33-00cf-4c5a-830d-d65d470930a7
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4c41d16d74da37a3bb099a46070b1163ebf9b56e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4206"></a>Aviso LNK4206 (Ferramentas de Vinculador)
informações de tipo pré-compilado não encontradas. 'filename' não vinculado ou substituído; Vinculando objeto como se nenhuma informação de depuração  
  
 O arquivo de objeto fornecido, compilado com [/Yc](../../build/reference/yc-create-precompiled-header-file.md), não foi especificado no comando LINK ou foi substituído.  
  
 Um cenário comum para esse aviso é quando o. obj que foi compilado com /Yc estiver em uma biblioteca, e onde existem referências a esse obj símbolo no seu código.  Nesse caso, o vinculador será não usar (ou até mesmo ver) o arquivo. obj.  Nessa situação, você deve recompilar seu código e usar [/Yl](../../build/reference/yl-inject-pch-reference-for-debug-library.md) para os objetos restantes (os objetos que não são compilados com /Yc).
