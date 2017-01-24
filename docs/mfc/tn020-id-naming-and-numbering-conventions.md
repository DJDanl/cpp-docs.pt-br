---
title: "TN020: conven&#231;&#245;es de nomenclatura de ID e numera&#231;&#227;o | Microsoft Docs"
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
  - "vc.id"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "identificadores de recursos"
  - "identificadores de recursos, nomenclatura e numeração"
  - "TN020"
ms.assetid: aecbd2cf-68b3-47f6-ae21-b1f507917245
caps.latest.revision: 17
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN020: conven&#231;&#245;es de nomenclatura de ID e numera&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa observação descreve a nomeação de ID e as convenções de numeração que o MFC 2.0 usa para recursos do, comandos, cadeias de caracteres, controles, e janelas filho.  
  
 A nomenclatura de MFC ID e as convenções de numeração devem atender aos seguintes requisitos:  
  
-   Forneça um padrão de nomeação consistente usado pela biblioteca MFC e aplicativos MFC que têm suporte do editor de recursos do Visual C\+\+.  Isso facilita para que o programador interprete o tipo e a origem de um recurso de sua ID  
  
-   Sublinhe a relação de 1 para forte entre determinados tipos de IDs.  
  
-   Conforme\-se os padrões mais amplamente usados para nomear IDs no windows.  
  
-   Divida o espaço de ID\- numeração.  Os números de identificação podem ser atribuídos pelo programador, por MFC, pelo windows, e os recursos de visual C\+\+\-edited.  O particionamento apropriado ajudará evitar a duplicação de números de ID.  
  
## A convenção de nomenclatura de prefixos de ID  
 Vários tipos de IDs podem ocorrer em um aplicativo.  A convenção de nomenclatura de MFC define prefixos diferentes para tipos de recursos diferentes.  
  
 MFC O usa o prefixo “IDR\_” para indicar uma ID de recurso que se aplica a vários tipos do recurso.  Por exemplo, para uma janela determinada do quadro, MFC o usa o mesmo prefixo “IDR\_” para indicar um menu, um acelerador, uma cadeia de caracteres e um recurso de ícone.  A tabela a seguir mostra vários prefixos e seu uso:  
  
|Prefixo|Uso|  
|-------------|---------|  
|IDR\_|Para os vários tipos de recursos \(principalmente usadas para menus, aceleradores, e fitas\).|  
|IDD\_|Para os recursos do modelo da caixa de diálogo \(por exemplo, IDD\_DIALOG1\).|  
|IDC\_|Para recursos do cursor.|  
|IDI\_|Para recursos do ícone.|  
|IDB\_|Para recursos de bitmap.|  
|IDS\_|Para recursos de cadeia de caracteres.|  
  
 Em um recurso de CAIXA FROM DIÁLOGO, o MFC segue estas convenções:  
  
|Prefixo ou rótulo|Uso|  
|-----------------------|---------|  
|IDOK, IDCANCEL|Para IDs padrão do botão de ação.|  
|IDC\_|Para outros controles da caixa de diálogo.|  
  
 O prefixo “IDC\_” também é usado para cursores.  Esse conflito de nomeação geralmente não é um problema porque um aplicativo típico terá alguns cursores e muitos controles da caixa de diálogo.  
  
 Em um recurso no menu, o MFC segue estas convenções:  
  
|Prefixo|Uso|  
|-------------|---------|  
|IDM\_|Para os itens de menu que não usam a arquitetura de comando MFC.|  
|ID\_|Para os comandos de menu que usam a arquitetura de comando MFC.|  
  
 Os comandos após a arquitetura de comando MFC devem ter um manipulador de comando de `ON_COMMAND` e pode ter um manipulador de `ON_UPDATE_COMMAND_UI` .  Se esses manipuladores de comando seguem a arquitetura de comando MFC, funcionará corretamente se estiverem associados a um comando de menu, um botão da barra de ferramentas, ou a um botão da barra da caixa de diálogo.  O mesmo prefixo “ID\_” é usado também para uma cadeia de caracteres de aviso de menu que é exibida na barra de mensagens do programa.  A maioria dos itens de menu em seu aplicativo devem seguir as convenções do comando MFC.  Todas as IDs padrão de comando \(por exemplo, `ID_FILE_NEW`\) seguem a convenção.  
  
 MFC O também usa “IDP\_” como uma forma especializada de cadeias de caracteres \(em vez de “IDS\_”\).  As cadeias de caracteres com o prefixo “IDP\_” são avisos, ou seja, cadeias de caracteres usadas nas caixas de mensagem. As cadeias de caracteres de “IDP\_” podem conter “%1 " e “%2 " como espaços reservados de cadeias de caracteres determinadas pelo programa. As cadeias de caracteres de “IDP\_” normalmente têm os tópicos da ajuda associados a eles, e as cadeias de caracteres de “IDS\_” não existe. As cadeias de caracteres de “IDP\_” são encontradas sempre, e as cadeias de caracteres de “IDS\_” não poderiam ser encontradas.  
  
 A biblioteca MFC também usa o prefixo “IDW\_” como uma forma especializada de IDs de controle \(em vez de “IDC\_”\).  Essas IDs são atribuídos às janelas filho como exibições e separadores por classes da estrutura.  As IDs de implementação de MFC são prefixados com “AFX\_”.  
  
## A convenção de ID\- numeração  
 A tabela a seguir lista os intervalos válidos para as IDs dos tipos específicos.  Alguns limites são limites técnicos de implementação, e outras são as convenções que são criadas para impedir que os IDs colidam com IDs predefinidos o windows ou as implementações padrão de MFC.  
  
 É altamente recomendável que você define todos os IDs dentro dos intervalos recomendados.  O limite inferior desses intervalos é 1 pois 0 não são usados.  É recomendável usar a convenção e uso comum 100 ou 101 como a primeira ID  
  
|Prefixo|Tipo de recurso|Intervalo válido|  
|-------------|---------------------|----------------------|  
|IDR\_|várias|1 0x6FFF direto|  
|IDD\_|modelos da caixa de diálogo|1 0x6FFF direto|  
|IDC\_, IDI\_, IDB\_|cursores, ícones, bitmaps|1 0x6FFF direto|  
|IDS\_, IDP\_|cadeias de caracteres gerais|1 0x7FFF direto|  
|ID\_|comandos|0x8000 com 0xDFFF|  
|IDC\_|controles|8 0xDFFF diretos|  
  
 As razões para esses limites variam:  
  
-   Por convenção, o valor de ID 0 não é usado.  
  
-   As restrições de implementação do windows restringem IDs true de recursos para ser menor ou igual a 0x7FFF.  
  
-   A estrutura interna MFC ele reserva esses intervalos:  
  
    -   0x7000 com 0x7FFF \(consulte afxres.h\)  
  
    -   0xE000 com 0xEFFF \(consulte afxres.h\)  
  
    -   16000 a 18000 \(consulte afxribbonres.h\)  
  
     Esses intervalos podem ser alterados em implementações futuras MFC.  
  
-   Vários comandos de sistema do windows usam o intervalo de 0xF000 a 0xFFFF.  
  
-   As IDs de controle de 1 a 7 são reservados para controles padrão como IDOK e IDCANCEL.  
  
-   O intervalo de 0x8000 a 0xFFFF para cadeias de caracteres é reservado para avisos no menu para comandos.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)