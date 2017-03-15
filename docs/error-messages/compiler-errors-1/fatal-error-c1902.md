---
title: Erro fatal C1902 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1902
dev_langs:
- C++
helpviewer_keywords:
- C1902
ms.assetid: 2dc066cc-fcb1-4725-8bcb-9f44dd0905b7
caps.latest.revision: 13
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
translationtype: Machine Translation
ms.sourcegitcommit: b551b1a7e0ae03a7de5108a1d114155786972847
ms.openlocfilehash: 79987719614dfa3075f9a9090ca1d97f6546ceb3
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1902"></a>Erro fatal C1902
incompatibilidade de Gerenciador de banco de dados do programa; Verifique a instalação  
  
Um arquivo de banco de dados do programa (. PDB) foi criado usando uma versão mais recente do mspdb*XXX*. dll que o compilador encontrado no sistema. Esse erro geralmente indica que mspdbsrv.exe ou mspdbcore.dll estão faltando ou tiverem diferentes versões de mspdb*XXX*. dll. (O *XXX* espaço reservado de mspdb*XXX*alterações de nome de arquivo. dll com cada versão do produto. Por exemplo, no Visual Studio 2015, o nome do arquivo é mspdb140.dll.)  
  
Verifique as versões correspondentes do mspdbsrv.exe, mspdbcore.dll e mspdb*XXX*. dll está instalado no seu sistema. Certifique-se de que as versões incompatíveis não foram copiadas para o diretório que contém as ferramentas do compilador e o link para a plataforma de destino. Por exemplo, talvez você tenha copiado os arquivos para que você pode chamar a ferramenta de compilador ou link do prompt de comando sem definir a **caminho** variável de ambiente adequadamente.
