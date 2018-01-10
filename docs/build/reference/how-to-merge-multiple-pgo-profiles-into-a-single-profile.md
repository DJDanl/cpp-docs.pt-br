---
title: "Como: mesclar vários perfis PGO em um único perfil | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- merging profiles
- profile-guided optimizations, merging profiles
ms.assetid: aab686b5-59dd-40d1-a04b-5064690f65a6
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 880e9fbba7852a9a7919e73f80b73e34394cd037
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-merge-multiple-pgo-profiles-into-a-single-profile"></a>Como mesclar vários perfis PGO em um único perfil
Otimização Guiada por perfil (PGO) é uma excelente ferramenta para criar binários otimizados com base em um cenário que é atribuído. Mas se você tiver um aplicativo que tem vários cenários importantes, ainda distintos; como você cria um único perfil PGO pode usar de vários cenários diferentes? No Visual Studio, o Gerenciador de PGO Pgomgr.exe, faz esse trabalho para você.  
  
 A sintaxe para a mesclagem de perfis é:  
  
```  
pgomgr /merge[:num] [.pgc_files] .pgd_files  
```  
  
 onde `num` é um peso opcional que está sendo usado para essa mesclagem. Os pesos são usados se existem alguns cenários que são mais importantes que outras pessoas ou se há cenários que estão para ser executado várias vezes.  
  
> [!NOTE]
>  O Gerenciador de PGO não funcionarão com dados de perfil obsoletos. Para mesclar um arquivo. PGC em um arquivo. PGD, o arquivo. PGC deve ser gerado por um executável que foi criado pelo mesmo invocação de link que gerou o arquivo. PGD.  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, o Gerenciador de PGO adicionará pgcFile.pgc para pgdFile.pgd seis vezes.  
  
```  
pgomgr /merge:6 pgcFile.pgc pgdFile.pgd  
```  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, o Gerenciador de PGO adicione pgcFile1.pgc e pgcFile2.pgc para pgdFile.pgd, duas vezes para cada arquivo. PGC.  
  
```  
pgomgr /merge:2 pgcFile1.pgc pgcFile2.pgc pgdFile.pgd  
```  
  
## <a name="example"></a>Exemplo  
 Se o Gerenciador de PGO é executado sem um arquivo. PGC, ele irá procurar o diretório local para todos os arquivos. PGC que têm o mesmo nome do arquivo. PGD concatenado com um sinal de exclamação (!) seguido por caracteres arbitrários. Se o diretório local tiver test!hello.pgc, test!1.pgc, test2.pgc e test.pgd de arquivos e o comando a seguir é executado do diretório local, em seguida, test!1.pgc e test!hello.pgc serão mescladas na test.pgd.  
  
```  
pgomgr /merge test.pgd  
```  
  
## <a name="see-also"></a>Consulte também  
 [Otimizações guiadas por perfil](../../build/reference/profile-guided-optimizations.md)