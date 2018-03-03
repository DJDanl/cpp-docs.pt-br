---
title: Sintaxe de partes de nome de arquivo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- syntax, filename-parts
- filename-parts syntax in NMAKE
- NMAKE program, syntax
ms.assetid: 48fe38e0-3f3b-40e6-894c-330ee775a656
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a481f8c461cb4fddd4acb090edb2f2b5fd18636d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="filename-parts-syntax"></a>Sintaxe de partes do nome de arquivo
Sintaxe de partes de nome de arquivo em comandos representa os componentes do nome de arquivo dependente primeiro (o que pode ser um dependente implícito). Componentes de nome de arquivo são unidade do arquivo, caminho, nome de base e extensão conforme especificado, não como ele existe no disco. Use **%s** representar o nome de arquivo completo. Use **% &#124;** [*partes*]**F** (uma barra vertical caractere segue o símbolo de porcentagem) para representar partes do nome de arquivo, onde *partes* pode ser zero ou mais das seguintes letras, em qualquer ordem.  
  
|Letra|Descrição|  
|------------|-----------------|  
|Nenhuma letra|Nome completo (mesmo que **%s**)|  
|**d**|Dirigir|  
|**p**|Caminho|  
|**f**|Nome base do arquivo|  
|**e**|Extensão de arquivo|  
  
 Por exemplo, se o nome do arquivo é c:\prog.exe:  
  
-   %s será c:\prog.exe  
  
-   % &#124; F será c:\prog.exe  
  
-   % &#124; será de dF com c  
  
-   % &#124; pF será c:\  
  
-   % &#124; fF será prog  
  
-   % &#124; eF será exe  
  
## <a name="see-also"></a>Consulte também  
 [Comandos em um makefile](../build/commands-in-a-makefile.md)