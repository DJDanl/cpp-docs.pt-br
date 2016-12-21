---
title: "Incluindo s&#237;mbolos compartilhados (somente leitura) ou calculados | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.symbol.shared.calculated"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "símbolos calculados"
  - "símbolos somente leitura"
  - "símbolos compartilhados"
  - "diretivas de símbolo"
  - "símbolos, calculado"
  - "símbolos, somente leitura"
  - "símbolos, shared"
ms.assetid: 32b77faf-a066-4371-a072-9a5b84c0766d
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Incluindo s&#237;mbolos compartilhados (somente leitura) ou calculados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Na primeira vez que o ambiente de desenvolvimento lê um arquivo de recurso criado por outro aplicativo, ele marca todos os arquivos de cabeçalho incluído como somente leitura.  Posteriormente, você pode usar o [caixa de diálogo recurso inclui](../windows/resource-includes-dialog-box.md) para adicionar arquivos de cabeçalho de símbolo somente leitura adicional.  
  
 Um motivo que você talvez queira usar definições de símbolo somente leitura é para arquivos de símbolo que você planeja compartilhar entre vários projetos.  
  
 Você também pode usar arquivos de símbolo incluído quando você tem os recursos existentes com as definições de símbolos que usa expressões em vez de inteiros simples para definir o valor do símbolo.  Por exemplo:  
  
```  
#define   IDC_CONTROL1 2100  
#define   IDC_CONTROL2 (IDC_CONTROL1+1)  
```  
  
 O ambiente corretamente interpretará esses símbolos calculados contanto que:  
  
-   Os símbolos calculados são colocados em um arquivo de símbolos somente leitura.  
  
-   O arquivo de recurso contém recursos aos quais esses símbolos calculados já estão atribuídos.  
  
-   Espera\-se uma expressão numérica.  
  
> [!NOTE]
>  Se uma cadeia de caracteres ou uma expressão numérica é esperada, a expressão não será avaliada.  
  
### Para incluir símbolos compartilhados \(somente leitura\) em seu arquivo de recursos  
  
1.  Em [exibição recurso](../windows/resource-view-window.md), clique em seu arquivo. RC e escolha [recurso inclui](../windows/resource-includes-dialog-box.md) no menu de atalho.  
  
    > [!NOTE]
    >  Se seu projeto ainda não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No **diretivas de símbolo somente leitura** caixa, use o **\#include** diretiva de compilador para especificar o arquivo onde você deseja que os símbolos somente leitura sejam mantidos.  
  
     Não chame o arquivo Resource.h, já que é o nome de arquivo normalmente usada pelo arquivo de cabeçalho de símbolo principal.  
  
    > [!NOTE]
    >  **Importante** o que você digita na caixa de diretivas de símbolo somente leitura é incluído no arquivo de recurso exatamente conforme você digita.  Certifique\-se de que você digitou não contém erros de ortografia ou sintaxe.  
  
     Use o **diretivas de símbolo somente leitura** caixa para incluir arquivos com apenas definições de símbolo.  Não inclua as definições de recurso. Caso contrário, as definições de recurso duplicado serão criadas quando o arquivo é salvo.  
  
3.  Coloque os símbolos no arquivo especificado por você.  
  
     Os símbolos nos arquivos incluídos dessa forma são avaliados sempre que você abrir o arquivo de recurso, mas elas não são substituídas no disco quando você salvar o arquivo.  
  
4.  Clique em **OK**.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, consulte [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Win32  
  
## Consulte também  
 [Restrições de nome do símbolo](../windows/symbol-name-restrictions.md)   
 [Restrições de valor do símbolo](../Topic/Symbol%20Value%20Restrictions.md)   
 [IDs de símbolo predefinido](../windows/predefined-symbol-ids.md)   
 [Símbolos: Identificadores de recursos](../mfc/symbols-resource-identifiers.md)