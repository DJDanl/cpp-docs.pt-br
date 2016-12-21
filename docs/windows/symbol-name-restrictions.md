---
title: "Restri&#231;&#245;es de nome do s&#237;mbolo | Microsoft Docs"
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
  - "vc.editors.symbol.restrictions.name"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "restrições, nomes de símbolos"
  - "nomes de símbolos"
  - "símbolos, nomes"
ms.assetid: 4ae7f695-ca86-4f4b-989a-fe6f89650ff7
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Restri&#231;&#245;es de nome do s&#237;mbolo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As restrições em nomes de símbolos são os seguintes:  
  
-   Todos os [símbolos](../mfc/symbols-resource-identifiers.md) deve ser exclusivo dentro do escopo do aplicativo.  Isso impede que as definições conflitantes de símbolo nos arquivos de cabeçalho.  
  
-   Os caracteres válidos para um nome de símbolo incluem A\-Z, a\-z, 0\-9 e sublinhados \(\_\).  
  
-   Os nomes de símbolo não podem começar com um número e são limitados a 247 caracteres.  
  
-   Nomes de símbolo não podem conter espaços.  
  
-   Nomes de símbolo não diferenciam maiúsculas de minúsculas, mas no caso da primeira definição de símbolo é preservado.  O arquivo de cabeçalho que define os símbolos é usado pelo compilador\/editor de recursos e programas do C\+\+ para fazer referência a recursos definidos em um arquivo de recurso.  Dois nomes de símbolo que diferem apenas em maiúsculas, o programa C\+\+ verá dois símbolos separados, enquanto o compilador\/editor de recurso verá os dois nomes como se referindo a um único símbolo.  
  
    > [!NOTE]
    >  Se você não seguir o esquema de nome de símbolo padrão \(ID\*\_\[keyword\]\) descrito abaixo, e seu nome de símbolo, por acaso, é o mesmo como uma palavra\-chave conhecida do compilador do script de recurso, tentar criar o arquivo de script de recurso resultará na geração de erro aparentemente aleatório que é difícil de diagnosticar.  Para evitar isso, seguir o esquema de nomeação padrão.  
  
 Nomes de símbolos têm prefixos descritivos que indicam o tipo de recurso ou objeto que eles representam.  Esses prefixos descritivos começam com a ID da combinação de texto.  O Microsoft Foundation Class Library \(MFC\) usa as convenções de nomenclatura de símbolo mostradas na tabela a seguir.  
  
|Categoria|Namespace|Usar|  
|---------------|---------------|----------|  
|Recursos|IDR IDD \_ IDC \_ IDI\_ IDB\_|Acelerador ou menu \(e recursos associados ou personalizados\) a caixa de diálogo Bitmap do ícone de Cursor|  
|Itens de menu|ID \_|Item de menu|  
|Comandos|ID \_|Comando|  
|Controles e janelas filho|IDC \_|Controle|  
|Cadeias de caracteres|IDS \_|Cadeia de caracteres na tabela de cadeia de caracteres|  
|MFC|AFX\_|Reservado para símbolos predefinidos do MFC|  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, consulte [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Alterando um símbolo ou um nome de símbolo \(ID\)](../windows/changing-a-symbol-or-symbol-name-id.md)   
 [Restrições de valor do símbolo](../Topic/Symbol%20Value%20Restrictions.md)   
 [IDs de símbolo predefinido](../windows/predefined-symbol-ids.md)