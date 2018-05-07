---
title: Redistribuindo um aplicativo ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ATL, redistributing
- redistributing ATL
- redistributing OLE DB templates
- OLE DB templates, redistributing
ms.assetid: 9a696b22-2345-43ec-826b-be7cb8cfd676
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5c824dd4ae174a4418c6744e592dd62dc54b9595
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="redistributing-an-atl-application"></a>Redistribuindo um aplicativo ATL
A partir do Visual Studio 2012, ATL Active Template Library () é uma biblioteca de somente cabeçalho. Projetos ATL não tem um Link dinâmico para opção ATL. Nenhuma biblioteca ATL redistribuível é necessária.  
  
 Se você redistribuir um aplicativo executável ATL, você deve registrar o arquivo .exe (e os controles dentro dele) emitindo o comando a seguir:  
  
```  
filename /regserver  
```  
  
 onde `filename` é o nome do arquivo executável.  
  
 No Visual Studio 2010, um projeto de ATL pode ser criado para um MinDependency ou uma configuração de MinSize. Uma configuração de MinDependency é o que você obtém quando você definir o **uso de ATL** propriedade **Link estático para ATL** no **geral** página de propriedades e defina o  **Biblioteca de tempo de execução** propriedade **multithread (/ MT)** no **geração de código** a página de propriedades (pasta C/C++).  
  
 Uma configuração de MinSize é o que você obtém quando você definir o **uso de ATL** propriedade **Link dinâmico para ATL** no **geral** página de propriedades ou conjunto o **em tempo de execução Biblioteca** propriedade **multi-threaded DLL (/ MD)** no **geração de código** a página de propriedades (pasta C/C++).  
  
 MinSize faz com que a saída de arquivo tão pequena quanto possível mas requerem que ATL100.dll e Msvcr100.dll (se você tiver selecionado o **multi-threaded DLL (/ MD)** opção) no computador de destino. ATL100.dll devem ser registradas no computador de destino para garantir que todas as funcionalidades ATL estão presente. ATL100.dll contém ANSI e Unicode exporta.  
  
 Se você compilar o projeto ATL ou modelos OLE DB de destino MinDependency, você não precisa instalar e registrar ATL100.dll no computador de destino, embora você pode obter uma imagem de programa maior.  
  
 Se você redistribuir um aplicativo executável ATL, você deve registrar o arquivo .exe (e os controles dentro dele) emitindo o comando a seguir:  
  
```  
filename /regserver  
```  
  
 onde `filename` é o nome do arquivo executável.  
  
 Para aplicativos de modelos OLE DB, certifique-se de que o computador de destino tem as versões mais recentes dos arquivos do Microsoft Data Access Components (MDAC). Para obter mais informações, consulte [redistribuindo arquivos de suporte do banco de dados](../ide/redistributing-database-support-files.md).  
  
## <a name="see-also"></a>Consulte também  
 [Redistribuindo arquivos do Visual C++](../ide/redistributing-visual-cpp-files.md)