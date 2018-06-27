---
title: 'TN023: Recursos MFC padrão | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mfc.resources
dev_langs:
- C++
helpviewer_keywords:
- resources [MFC]
- TN023
- standard resources
ms.assetid: 60af8415-c576-4c2f-a711-ca5da0b9a1f2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 967485f358d6659d759f2651c80c9390bff0b912
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36952031"
---
# <a name="tn023-standard-mfc-resources"></a>TN023: recursos MFC padrão
Esta anotação descreve os recursos padrão fornecida com e necessárias para a biblioteca do MFC.  
  
## <a name="standard-resources"></a>Recursos padrão  
 MFC oferece duas categorias de recursos predefinidos que você pode usar em seu aplicativo: recursos de clip-art e recursos de estrutura padrão.  
  
 Recursos de clip-art são recursos adicionais que o framework não dependem, mas que talvez você queira adicionar a interface do usuário do seu aplicativo. Os seguintes recursos de clip-art estão contidos no exemplo de MFC geral [clip-art](../visual-cpp-samples.md):  
  
-   Common.RC: Um único arquivo de recursos que contém:  
  
    -   Uma grande coleção de ícones que representam uma variedade de tarefas de processamento de dados e de negócios.  
  
    -   Vários cursores comuns (Consulte também Afxres.rc).  
  
    -   Um bitmap de barra de ferramentas que contém vários botões de barra de ferramentas.  
  
    -   Os recursos de bitmap e o ícone que são usados por Commdlg.  
  
-   Indicate.RC: Contém recursos de cadeia de caracteres para os indicadores de estado de chave com a barra de status, como "CAP" Caps Lock.  
  
-   Prompts.RC: Contém recursos de cadeia de caracteres de prompt de menu para cada comando predefinido, como "Criar um novo documento" para ID_FILE_NEW.  
  
-   Commdlg.RC: Um arquivo de RC compatível do Visual C++ que contém os modelos de caixa de diálogo COMMDLG padrão.  
  
 Recursos de estrutura padrão são recursos com IDs definidos AFX framework depende para implementações internas. Raramente, você precisará alterar esses recursos definidos AFX. Se você fizer isso, você deve seguir o procedimento descrito neste tópico.  
  
 Os seguintes recursos de estrutura estão contidos no diretório MFC\INCLUDE:  
  
-   Afxres.RC: Recursos comuns usados pelo framework.  
  
-   Afxprint.RC: Recursos específicos de impressão.  
  
-   Afxolecl.RC: Os recursos específicos de aplicativos de cliente OLE.  
  
-   Afxolev.RC: Os recursos específicos de aplicativos de servidor completos OLE.  
  
## <a name="using-clip-art-resources"></a>Usando recursos de Clip-Art  
  
#### <a name="to-use-a-clip-art-binary-resource"></a>Para usar um recurso binário clip-art  
  
1.  Abra o arquivo de recurso do aplicativo no Visual C++.  
  
2.  Abra Common.rc. Esse arquivo contém todos os recursos do binário clip-art. Isso pode levar algum tempo, porque o arquivo Common.rc é compilado.  
  
3.  Mantenha pressionada a tecla CTRL enquanto você arrasta os recursos que você deseja usar na Common.rc ao arquivo de recurso do aplicativo.  
  
 Para usar outros recursos de clip-art, siga as mesmas etapas. A única diferença é que você abrirá o arquivo. rc apropriada em vez de Common.rc.  
  
> [!NOTE]
>  Tenha cuidado para não mover acidentalmente recursos fora do Common.rc permanentemente. Se você mantiver a tecla CTRL enquanto arrasta recursos, você criará uma cópia. Se você não mantiver CTRL pressionada enquanto arrasta, os recursos serão movidos. Se você estiver preocupado que você pode acidentalmente fez alterações no arquivo Common.rc, clique em "Não" quando for perguntado se deseja salvar as alterações para Common.rc.  
  
> [!NOTE]
>  Os arquivos de recursos de RC possuem um recurso TEXTINCLUDE especial que irá impedi-lo acidentalmente salve sobre os arquivos. rc standard.  
  
### <a name="customizing-standard-framework-resources"></a>Personalizando recursos de estrutura padrão  
 Recursos de estrutura padrão normalmente são incluídos em um aplicativo usando o #include comando no arquivo de recurso do aplicativo. AppWizard irá gerar um arquivo de recurso. Este arquivo inclui os recursos de estrutura padrão apropriado, dependendo de quais opções de AppWizard você selecionar. Você pode revisar, adicionar ou remover a quais recursos estão incluídos alterando as diretivas de tempo de compilação. Para fazer isso, abra o **recurso** menu e selecione **definir inclui**. Examinar as diretivas de tempo de compilação"" Editar item. Por exemplo:  
  
```  
#include "afxres.rc"  
#include "afxprint.rc"  
```  
  
 O caso mais comum de personalização de recursos de estrutura padrão está adicionando ou removendo adicionais inclui para impressão, cliente OLE e o suporte de servidor OLE.  
  
 Em alguns casos raros, que talvez você queira personalizar o conteúdo dos recursos de estrutura padrão para seu aplicativo em particular, não apenas adicionar e remover o arquivo inteiro. As etapas a seguir mostram como você pode limitar os recursos que estão incluídos:  
  
##### <a name="to-customize-the-contents-of-a-standard-resource-file"></a>Para personalizar o conteúdo de um arquivo de recurso padrão  
  
1.  Abra o arquivo de recurso no Visual C++.  
  
2.  Usando o comando inclui o recurso definido, remova o `#include` para o arquivo. rc padrão que você deseja personalizar. Por exemplo, para personalizar a barra de ferramentas de visualização de impressão, remova o `#include "afxprint.rc"` linha.  
  
3.  Abra os arquivos de recursos padrão apropriado no MFC\INCLUDE. Seguindo o exemplo neste tópico, o arquivo apropriado é MFC\Include\Aafxprint.rc  
  
4.  Copie todos os recursos do arquivo. rc padrão para o arquivo de recurso do aplicativo.  
  
5.  Modificar a cópia dos recursos padrão em seu arquivo de recurso do aplicativo.  
  
> [!NOTE]
>  Não modifique os recursos diretamente nos arquivos. rc standard. Isso irá modificar os recursos disponíveis em todos os aplicativos, não apenas naquele que você está trabalhando no momento.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

