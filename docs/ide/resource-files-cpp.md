---
title: Arquivos de recurso (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- resource files
- resources [C++]
- file types [C++], resource files
ms.assetid: 338a4a0f-0c62-4ef1-a34f-5d86262d93a4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0c295b9a3aa4996cdcd2afb17b5a4ff4c90c1159
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="resource-files-c"></a>Arquivos de recurso (C++)
Recursos são elementos de interface que fornecem informações para o usuário. Bitmaps, ícones, barras de ferramentas e cursores são todos os recursos. Alguns recursos podem ser manipulados para executar uma ação, como selecionar um menu ou inserir dados na caixa de diálogo.  
  
 Consulte [trabalhar com recursos](../windows/working-with-resource-files.md) para obter mais informações.  
  
|Nome do arquivo|Local do diretório|Local do Gerenciador de solução|Descrição|  
|---------------|------------------------|--------------------------------|-----------------|  
|*NomeDoProjeto*. rc|*Projname*|Arquivos de fonte|O arquivo de script de recurso para o projeto. O arquivo de script de recurso contém o seguinte, dependendo do tipo de projeto e o suporte selecionado para o projeto (por exemplo, barras de ferramentas, caixas de diálogo ou HTML):<br /><br /> -Definição de menu padrão.<br />-Tabelas accelerator e cadeia de caracteres.<br />-Padrão **sobre** caixa de diálogo.<br />-Outras caixas de diálogo.<br />-Arquivo de ícone (res\\*NomeDoProjeto*. ico).<br />-Informações de versão.<br />-Bitmaps.<br />-Barra de ferramentas.<br />-Arquivos HTML.<br /><br /> O arquivo de recurso inclui o arquivo Afxres.rc para recursos padrão do Microsoft Foundation Class.|  
|Resource.h|*Projname*|Arquivos de cabeçalho|O arquivo de cabeçalho de recurso que inclui as definições para os recursos usados pelo projeto.|  
|*NomeDoProjeto*. RC2|*NomeDoProjeto*\res|Arquivos de fonte|O arquivo de script que contém recursos adicionais usados pelo projeto. Você pode incluir o arquivo. RC2 na parte superior do arquivo. RC do projeto.<br /><br /> Um arquivo. RC2 é útil para incluir os recursos usados por vários projetos diferentes. Em vez de criar os mesmos recursos várias vezes para projetos diferentes, você pode colocá-los em um arquivo. RC2 e incluir o arquivo. RC2 no arquivo. rc principal.|  
|*NomeDoProjeto*. def|*Projname*|Arquivos de fonte|O arquivo de definição de módulo para um projeto de DLL. Para um controle, ele fornece o nome e a descrição do controle, bem como o tamanho do heap de tempo de execução.|  
|*NomeDoProjeto*. ico|*NomeDoProjeto*\res|Arquivos de recursos|O arquivo de ícone para o projeto ou controle. Esse ícone é exibido quando o aplicativo é minimizado. Ele também é usado no aplicativo de **sobre** caixa. Por padrão, MFC fornece o ícone MFC e ATL fornece o ícone ATL.|  
|*NomeDoProjeto*Doc.ico|*NomeDoProjeto*\res|Arquivos de recursos|O arquivo de ícone para um projeto MFC que inclui suporte para arquitetura de documento/exibição.|  
|ToolBar.bmp|*NomeDoProjeto*\res|Arquivos de recursos|O arquivo de bitmap que representa o aplicativo ou controle em uma barra de ferramentas ou uma paleta. Este bitmap está incluído no arquivo de recurso do projeto. A barra de ferramentas inicial e a barra de status são construídos no **CMainFrame** classe.|  
|Ribbon.mfcribbon ms|*NomeDoProjeto*\res|Arquivos de recursos|O arquivo de recurso que contém o código XML que define os atributos, botões e controles da faixa de opções. Para obter mais informações, consulte [Designer da faixa de opções (MFC)](../mfc/ribbon-designer-mfc.md).|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)