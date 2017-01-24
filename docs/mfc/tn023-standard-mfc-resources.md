---
title: "TN023: recursos MFC padr&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.resources"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "recursos [MFC]"
  - "recursos padrão"
  - "TN023"
ms.assetid: 60af8415-c576-4c2f-a711-ca5da0b9a1f2
caps.latest.revision: 15
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN023: recursos MFC padr&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa observação descreve os recursos padrão fornecidos com e necessários pela biblioteca MFC.  
  
## Recursos padrão  
 MFC O oferece duas categorias de recursos predefinidos que você pode usar em seu aplicativo: recursos de clip\-art e recursos padrão da estrutura.  
  
 Os recursos de clip\-art são recursos adicionais que a estrutura não depende, mas que talvez você queira adicionar à interface de usuário de seu aplicativo.  Os seguintes recursos de clip\-art estão contidos no exemplo [CLIPART](../top/visual-cpp-samples.md)gerais de MFC:  
  
-   Common.rc: Um único arquivo de recursos que contém:  
  
    -   Uma grande coleção de ícones que representam uma variedade de tarefas comerciais e de processamento de dados.  
  
    -   Vários cursores comum \(consulte também Afxres.rc\).  
  
    -   Um bitmap da barra de ferramentas que contém vários botões da barra de ferramentas.  
  
    -   Os recursos de bitmap e do ícone que são usados por Commdlg.dll.  
  
-   Indicate.rc: Contém recursos de cadeia de caracteres para os indicadores de estado de chave da barra de status, como “CAP” para o bloqueio de capacetes.  
  
-   Prompts.rc: Contém recursos de cadeia de caracteres de menu\- aviso para cada comando predefinido, como “criar um novo documento” para `ID_FILE_NEW`.  
  
-   Commdlg.rc: Um arquivo correspondente do Visual C\+\+ .rc que contém os modelos da caixa de diálogo de COMMDLG padrão.  
  
 Os recursos padrão da estrutura são recursos com IDs AFX\- definidos que a estrutura depende para implementações internas.  Você precisará raramente de alterar esses recursos AFX\- definidos.  Se você fizer isso, siga o procedimento descrito mais adiante neste tópico.  
  
 Os seguintes recursos da estrutura são contidos em MFC \\ INCLUDE o diretório:  
  
-   Afxres.rc: Recursos comuns usados pela estrutura.  
  
-   Afxprint.rc: Recursos específicos da impressão.  
  
-   Afxolecl.rc: Recursos específicos para aplicativos cliente OLE habilitados.  
  
-   Afxolev.rc: Recursos específicos para aplicativos para servidores com OLE DB completo.  
  
## Usando recursos de clip\-art  
  
#### Para usar um recurso binária de clip\-art  
  
1.  Abra o arquivo de recurso do aplicativo no Visual C\+\+.  
  
2.  Abra Common.rc.  Esse arquivo contém todos os recursos binários de clip\-art.  Isso pode demorar um pouco como o arquivo de Common.rc é criado.  
  
3.  Mantenha a tecla CTRL pressionada enquanto você arrastar os recursos que você deseja usar Common.rc do arquivo de recurso do seu aplicativo.  
  
 Para usar outros recursos de clip\-art, siga as mesmas etapas.  A única diferença é que você abrir o arquivo apropriado de .rc em vez de Common.rc.  
  
> [!NOTE]
>  Tenha cuidado para não mover querer permanentemente recursos fora de Common.rc.  Se você mantém a tecla CTRL enquanto você arrasta recursos, você criará uma cópia.  Se você não mantém a tecla CTRL pressionada enquanto você arrasta, os recursos serão movidos.  Se você estiver preocupado acidentalmente que você pode ter feito alterações no arquivo de Common.rc, clique em caso de “não” quando ele será perguntado se você deseja salvar as alterações a Common.rc.  
  
> [!NOTE]
>  Os arquivos de recursos de .rc têm um recurso especial de `TEXTINCLUDE` em que eles impedirão que você salvou acidentalmente sobre os arquivos de .rc padrão.  
  
### Personalizando recursos padrão da estrutura  
 Os recursos padrão da estrutura são incluídos em geral em um aplicativo usando o comando de \#include no arquivo de recurso de um aplicativo.  AppWizard irá gerar um arquivo de recurso.  Este arquivo inclui os recursos da estrutura do padrão apropriado, dependendo das opções de AppWizard selecionados.  Você pode examinar, adicionar ou remover recursos que são incluídos alterar as políticas de tempo de compilação.  Para fazer isso, abra o menu de **Recurso** e selecione **Inclui O conjunto**.  Procure “do item de edição das políticas tempo de compilação”.  Por exemplo:  
  
```  
#include "afxres.rc"  
#include "afxprint.rc"  
```  
  
 A maioria dos exemplos comuns de personalização de recursos padrão da estrutura serão adicionar ou remover inclui adicional para imprimir, o cliente OLE, e o suporte OLE do servidor.  
  
 Em alguns casos raros você pode desejar personalizar o conteúdo de recursos padrão da estrutura do seu aplicativo específico, para adicionar e remover e não apenas o arquivo inteiro.  As etapas de serviço ws\-management mostram como você pode limitar os recursos que são incluídos:  
  
##### Para personalizar o conteúdo de um arquivo de recursos padrão  
  
1.  Abra o arquivo de recurso no Visual C\+\+.  
  
2.  Usando o recurso que o cluster incluir o comando, remova `#include` para o arquivo de .rc padrão que você deseja personalizar.  Por exemplo, para personalizar a barra de ferramentas de visualização de impressão, remova a linha de `#include "afxprint.rc"` .  
  
3.  Abrir os arquivos de recursos do padrão apropriado em MFC \\ INCLUA\-OS.  Seguindo oe exemplo anterior neste tópico, o arquivo apropriado é MFC\\Include\\Aafxprint.rc  
  
4.  Copiar todos os recursos de arquivo padrão de .rc ao seu arquivo de recurso de aplicativo.  
  
5.  Modifique a cópia de recursos padrão em seu arquivo de recurso de aplicativo.  
  
> [!NOTE]
>  Não modifique os recursos diretamente nos arquivos de .rc padrão.  Isso alterará os recursos disponíveis em cada aplicativo, não apenas naquele que você está trabalhando no momento.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)