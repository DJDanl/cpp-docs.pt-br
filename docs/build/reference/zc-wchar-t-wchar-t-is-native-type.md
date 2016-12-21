---
title: "/Zc:wchar_t (wchar_t &#233; do tipo nativo) | Microsoft Docs"
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
  - "VC.Project.VCCLWCECompilerTool.TreatWChar_tAsBuiltInType"
  - "VC.Project.VCCLCompilerTool.TreatWChar_tAsBuiltInType"
  - "/Zc:wchar_t"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opções do compilador /Zc [C++]"
  - "Opções de compilador de conformidade"
  - "Tipo wchar_t"
  - "opções de compilador Zc [C++]"
  - "opções de compilador -Zc [C++]"
ms.assetid: b0de5a84-da72-4e5a-9a4e-541099f939e0
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Zc:wchar_t (wchar_t &#233; do tipo nativo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Analise `wchar_t` como um tipo interno de acordo com o padrão C\+\+.  Por padrão, **\/Zc:wchar\_t** é ativado.  
  
## Sintaxe  
  
```  
/Zc:wchar_t[-]  
```  
  
## Comentários  
 Se **\/Zc:wchar\_t** estiver ativado, `wchar_t` será mapeado para tipo nativo específico da Microsoft `__wchar_t`.  Se **\/Zc:wchar\_t\-** \(com um sinal de subtração\) for especificado, `wchar_t` será mapeado para um `typedef` de `unsigned short`.  \(No Visual C\+\+ 6.0 e versões anteriores, `wchar_t` não era implementado como tipo interno, mas era declarado em wchar.h como `typedef` de `unsigned short`.\) Não recomendamos **\/Zc:wchar\_t\-** porque o padrão C\+\+ requer que `wchar_t` seja um tipo interno.  Usar a versão `typedef` pode causar problemas de portabilidade.  Se você atualizar de versões anteriores do Visual C\+\+ e encontrar o erro [C2664](../../error-messages/compiler-errors-2/compiler-error-c2664.md) do compilador porque o código está tentando converter implicitamente `wchar_t` em `unsigned short`, recomendamos alterar o código para corrigir o erro, em vez de definir **\/Zc:wchar\_t\-**.  
  
 A Microsoft implementa `wchar_t` como um valor sem sinal de dois bytes.  Para obter mais informações sobre `wchar_t`, consulte [Intervalos de tipos de dados](../../cpp/data-type-ranges.md) e [Tipos fundamentais](../../cpp/fundamental-types-cpp.md).  
  
 Se você escrever um novo código que precisa interoperar com um código mais antigo que ainda que use a versão `typedef` de `wchar_t`, poderá fornecer sobrecargas para as variações `unsigned short` e `__wchar_t` de `wchar_t`, para que seu código possa ser vinculado pelo código compilado com **\/Zc:wchar\_t** ou o código compilado sem ele.  Caso contrário, você precisará fornecer duas diferentes compilações da biblioteca – uma com e outra sem **\/Zc:wchar\_t** habilitado.  Mesmo nesse caso, é recomendável compilar o código mais antigo usando o mesmo compilador que você usa para compilar o novo código.  Nunca misture binários compilados com compiladores diferentes.  
  
 Quando **\/Zc:wchar\_t** é especificado, os símbolos **\_WCHAR\_T\_DEFINED** e **\_NATIVE\_WCHAR\_T\_DEFINED** são definidos.  Para obter mais informações, consulte [Macros predefinidas](../../preprocessor/predefined-macros.md).  
  
 Se seu código usa as funções globais COM do compilador, como **\/Zc:wchar\_t** agora é ativado por padrão, recomendamos que você altere referências explícitas a comsupp.lib – do [pragma de comentário](../../preprocessor/comment-c-cpp.md) ou na linha de comando – para comsuppw.lib ou comsuppwd.lib.  \(Se você tiver de compilar com **\/Zc:wchar\_t\-**, use comsupp.lib.\) Se você incluir o arquivo de cabeçalho comdef.h, a biblioteca correta será especificada para você.  Para obter informações sobre o suporte para COM do compilador, consulte [Suporte COM do compilador](../Topic/Compiler%20COM%20Support.md).  
  
 O tipo `wchar_t` não tem suporte quando você compila código C.  Para obter mais informações sobre problemas de conformidade com o Visual C\+\+, consulte [Comportamento não padrão](../Topic/Nonstandard%20Behavior.md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No painel esquerdo, expanda **Propriedades de Configuração**, **C\/C\+\+** e selecione **Linguagem**.  
  
3.  Modifique a propriedade de **Trate WChar\_t Como um Tipo Interno**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.TreatWChar_tAsBuiltInType%2A>.  
  
## Consulte também  
 [\/Zc \(conformidade\)](../../build/reference/zc-conformance.md)