---
title: Criando um recurso de dados ou novo personalizado | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.editors.binary
dev_langs: C++
helpviewer_keywords:
- custom resources [C++]
- data resources [C++]
- resources [Visual Studio], creating
ms.assetid: 9918bf96-38fa-43a1-a384-572f95d84950
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: ff1beb01e08ea78f96b7f161e7f3ffc1110ff63b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="creating-a-new-custom-or-data-resource"></a>Criando um recurso de dados ou novo personalizado
Você pode criar um novo recurso de dados ou personalizado, colocando o recurso em um arquivo separado, usando a sintaxe de arquivo de script (. rc) do recurso normal e, em seguida, incluindo o arquivo clicando duas vezes o seu projeto no Gerenciador de soluções e clicando em **recurso inclui**  no menu de atalho.  
  
### <a name="to-create-a-new-custom-or-data-resource"></a>Para criar um novo recurso personalizados ou de dados  
  
1. [Criar um arquivo. rc](../windows/how-to-create-a-resource-script-file.md) que contém o recurso personalizado ou dados.  
  
     Você pode digitar dados personalizados em um arquivo. rc como cadeias de caracteres entre aspas com terminação nula ou como inteiros em formato decimal, hexadecimal ou octal.  
  
2.  Em **Solution Explorer**, clique o arquivo. RC do projeto e clique em **inclui recursos** no menu de atalho.  
  
3.  No **diretivas de tempo de compilação** , digite um **#include** instrução que fornece o nome do arquivo que contém o recurso personalizado. Por exemplo:  
  
 ```  
    #include mydata.rc  
 ```  
  
     Verifique se a sintaxe e a ortografia do que você digita estão corretos. O conteúdo do **diretivas de tempo de compilação** caixa são inseridos no arquivo de script de recurso exatamente como digitado-los.  
  
4.  Clique em **Okey** para registrar as alterações.  
  
 É outra maneira de criar um recurso personalizado importar um arquivo externo como o recurso personalizado. Para obter mais informações, consulte [importando e exportando recursos](../windows/how-to-import-and-export-resources.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](https://msdn.microsoft.com/library/f45fce5x.aspx) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](https://msdn.microsoft.com/library/xbx3z216.aspx). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](https://msdn.microsoft.com/library/h6270d0z.aspx).  
  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor binário](binary-editor.md)

