---
title: "-FS (forçar gravações PDB síncronas) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /FS
dev_langs: C++
helpviewer_keywords:
- -FS compiler option [C++]
- /FS compiler option [C++]
ms.assetid: b2caaffe-f6e1-4963-b068-648f06b105e0
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: a29b5f58517a8348c20bb233491aec01fda7f771
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="fs-force-synchronous-pdb-writes"></a>/FS (Forçar gravações PDB síncronas)
Força grava o arquivo de programa (PDB) de banco de dados — criado por [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) ou [/ZI](../../build/reference/z7-zi-zi-debug-information-format.md)— a ser serializado por meio de MSPDBSRV. EXE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/FS  
```  
  
## <a name="remarks"></a>Comentários  
 Por padrão, quando **/Zi** ou **/ZI** for especificado, o compilador bloqueia arquivos PDB para gravar informações de tipo e informações simbólicas de depuração. Isso pode reduzir significativamente o tempo necessário ao compilador para gerar informações de tipo quando o número de tipos é grande. Se outro processo bloquear temporariamente o arquivo PDB — por exemplo, um programa antivírus — gravações pelo compilador poderão falhar e pode ocorrer um erro fatal. Esse problema também pode ocorrer quando várias cópias de cl.exe acessar o mesmo arquivo PDB — por exemplo, se sua solução tiver independente projetos que usam o mesmo intermediário de pastas ou diretórios de saída e compilações paralelas estão habilitadas. O **/FS** opção de compilador impede que o compilador bloqueando o arquivo PDB e forçará as gravações percorrer MSPDBSRV. EXE, que serializa o acesso. Isso pode tornar builds significativamente maiores, e ela não impede que todos os erros que podem ocorrer quando várias instâncias do cl.exe acessarem o arquivo PDB ao mesmo tempo. É recomendável que você altere sua solução para que os projetos independentes escreva separar intermediário e locais de saída, ou que você faça um dos projetos depende do outro para compilações de projeto de equipe serializado.  
  
 O [/MP](../../build/reference/mp-build-with-multiple-processes.md) opção habilita **/FS** por padrão.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Modificar o **opções adicionais** propriedade incluir `/FS` e, em seguida, escolha **Okey**.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)