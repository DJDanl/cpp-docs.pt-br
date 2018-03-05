---
title: "-Zc: wchar_t (wchar_t é do tipo nativo) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLWCECompilerTool.TreatWChar_tAsBuiltInType
- VC.Project.VCCLCompilerTool.TreatWChar_tAsBuiltInType
- /Zc:wchar_t
dev_langs:
- C++
helpviewer_keywords:
- /Zc compiler options [C++]
- -Zc compiler options [C++]
- wchar_t type
- Conformance compiler options
- Zc compiler options [C++]
ms.assetid: b0de5a84-da72-4e5a-9a4e-541099f939e0
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3375e39120fdc8f2b0d8d5502aa6def997511ff5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="zcwchart-wchart-is-native-type"></a>/Zc:wchar_t (wchar_t é do tipo nativo)
Analise `wchar_t` como um tipo interno de acordo com o padrão C++. Por padrão, **/ZC:** está em.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Zc:wchar_t[-]  
```  
  
## <a name="remarks"></a>Comentários  
 Se **/ZC:** está ativada, `wchar_t` mapeia para o tipo nativo específicas da Microsoft `__wchar_t`. Se **/Zc:wchar_t-** (com um sinal de subtração) for especificado, `wchar_t` é mapeado para um `typedef` para `unsigned short`. (No Visual C++ 6.0 e versões anteriores, `wchar_t` não era implementado como tipo interno, mas era declarado em wchar.h como `typedef` de `unsigned short`.) Não é recomendável **/Zc:wchar_t-** porque o padrão C++ requer que `wchar_t` ser um tipo interno. Usar a versão `typedef` pode causar problemas de portabilidade. Se você atualizar de versões anteriores do Visual C++ e encontrar o erro do compilador [C2664](../../error-messages/compiler-errors-2/compiler-error-c2664.md) porque o código está tentando converter implicitamente um `wchar_t` para `unsigned short`, recomendamos que você altere o código para corrigir o erro, em vez disso configuração **/Zc:wchar_t-**.  
  
 A Microsoft implementa `wchar_t` como um valor sem sinal de dois bytes. Para obter mais informações sobre `wchar_t`, consulte [intervalos de tipos de dados](../../cpp/data-type-ranges.md) e [tipos fundamentais](../../cpp/fundamental-types-cpp.md).  
  
 Se você escrever novo código que tem para interoperar com o código anterior ainda usa o `typedef` versão do `wchar_t`, você pode fornecer sobrecargas para ambos os `unsigned short` e `__wchar_t` variações de `wchar_t`, de modo que seu código pode ser vinculado a o código compilado com **/ZC:** ou código compilado sem ele. Caso contrário, você precisa fornecer duas diferentes compilações da biblioteca de — um com e sem **/ZC:** habilitado. Mesmo nesse caso, é recomendável compilar o código mais antigo usando o mesmo compilador que você usa para compilar o novo código. Nunca misture binários compilados com compiladores diferentes.  
  
 Quando **/ZC:** for especificado, **wchar_t_defined** e **native_wchar_t_defined** símbolos são definidos. Para obter mais informações, consulte [Macros predefinidas](../../preprocessor/predefined-macros.md).  
  
 Se seu código usa as funções globais COM do compilador, pois **/ZC:** está agora em por padrão, é recomendável que você altere as referências explícitas aos comsupp.lib—from o [pragma de comentário](../../preprocessor/comment-c-cpp.md) ou sobre o comando linha — comsuppw.lib ou comsuppwd.lib. (Se você deve compilar com **/Zc:wchar_t-**, use comsupp.lib.) Se você incluir o arquivo de cabeçalho comdef.h, a biblioteca correta será especificada para você. Para obter informações sobre o suporte de COM do compilador, consulte [compilador COM suporte](../../cpp/compiler-com-support.md).  
  
 O tipo `wchar_t` não tem suporte quando você compila código C. Para obter mais informações sobre problemas de conformidade com o Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No painel esquerdo, expanda **propriedades de configuração**, **C/C++**e, em seguida, selecione **idioma**.  
  
3.  Modificar o **tratar wchar_t como tipo interno** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.TreatWChar_tAsBuiltInType%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [/ZC (conformidade)](../../build/reference/zc-conformance.md)