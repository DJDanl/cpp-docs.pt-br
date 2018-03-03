---
title: "Arquivos de cabeçalho pré-compilado | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- stdafx.h
dev_langs:
- C++
helpviewer_keywords:
- stdafx.h
- PCH files, file descriptions
- .pch files, file descriptions
- precompiled header files, file descriptions
- stdafx.cpp
ms.assetid: 8228d87a-5609-41f3-9697-b16094c000e5
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1208b000f57397764277cc0a43e223f7c781a06e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="precompiled-header-files"></a>Arquivos de cabeçalho pré-compilado
Esses arquivos são usados para criar um arquivo de cabeçalho pré-compilado *NomeDoProjeto*Stdafx.obj de arquivos. pch e tipos de pré-compilado.  
  
 Esses arquivos estão localizados no *NomeDoProjeto* directory. No Gerenciador de soluções, Stdafx. h está na pasta arquivos de cabeçalho e Stdafx está localizado na pasta arquivos de origem.  
  
|Nome do arquivo|Descrição|  
|---------------|-----------------|  
|Stdafx. h|Um arquivo de inclusão para arquivos de inclusão padrão do sistema e para os arquivos de inclusão específicos do projeto que são usados com frequência, mas que raramente são alterados.<br /><br /> Você não deve definir ou cancele qualquer as macros _AFX_NO_XXX Stdafx. h; Consulte o artigo da Base de dados de Conhecimento "PRB: ocorrer problemas ao definir _AFX_NO_XXX". Você pode encontrar artigos da Base de dados de Conhecimento na MSDN Library ou no [support.microsoft.com/ http://](http://%20support.microsoft.com/).|  
|Stdafx.cpp|Contém a diretiva de pré-processador `#include "stdafx.h"` e adiciona incluir arquivos para tipos pré-compilado. Arquivos pré-compilado de qualquer tipo, incluindo arquivos de cabeçalho, oferecem suporte a mais rápidos de compilação, restringindo a compilação somente para aqueles arquivos que precisam dele. Depois que o projeto é compilado na primeira vez, você observará muito mais rápido criar vezes em compilações subsequentes por causa da presença dos arquivos de cabeçalho pré-compilado.|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)   
 [Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)