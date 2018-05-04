---
title: Sintaxe de partes de nome de arquivo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- syntax, filename-parts
- filename-parts syntax in NMAKE
- NMAKE program, syntax
ms.assetid: 48fe38e0-3f3b-40e6-894c-330ee775a656
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d807087be171a2ad63ed37a8b359c3200c812040
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="filename-parts-syntax"></a>Sintaxe de partes do nome de arquivo
Sintaxe de partes de nome de arquivo em comandos representa os componentes do nome de arquivo dependente primeiro (o que pode ser um dependente implícito). Componentes de nome de arquivo são unidade do arquivo, caminho, nome de base e extensão conforme especificado, não como ele existe no disco. Use **%s** representar o nome de arquivo completo. Use **%&#124;**[*partes*]**F** (uma barra vertical caractere segue o símbolo de porcentagem) para representar partes do nome de arquivo, onde *partes*pode ser zero ou mais letras a seguir, em qualquer ordem.  
  
|Letra|Descrição|  
|------------|-----------------|  
|Nenhuma letra|Nome completo (mesmo que **%s**)|  
|**d**|Dirigir|  
|**p**|Caminho|  
|**f**|Nome base do arquivo|  
|**e**|Extensão de arquivo|  
  
 Por exemplo, se o nome do arquivo é c:\prog.exe:  
  
-   %s será c:\prog.exe  
  
-   %&#124;F será c:\prog.exe  
  
-   %&#124;dF será c  
  
-   %&#124;pF será c:\  
  
-   %&#124;fF será prog  
  
-   %&#124;eF será exe  
  
## <a name="see-also"></a>Consulte também  
 [Comandos em um makefile](../build/commands-in-a-makefile.md)