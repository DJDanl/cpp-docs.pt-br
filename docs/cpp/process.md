---
title: processo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- process_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], process
- process __declspec keyword
ms.assetid: 60eecc2f-4eef-4567-b9db-aaed34733023
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: d4f2500adaaa7941444b22d7ce548370fc370533
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="process"></a>process
Especifica que o processo de aplicativo gerenciado deve ter uma única cópia de uma determinada variável global, variável de membro estática ou variável local estática compartilhada por todos os domínios de aplicativo no processo. Isso é usado principalmente para ser usado ao compilar com **/clr: puro**, pois em **/clr: pure** são variáveis globais e estáticos por domínio de aplicativo, por padrão. As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015. Ao compilar com **/clr**, variáveis globais e estáticos são por processo por padrão (não precisa usar `__declspec(process)`.  
  
 Somente uma variável global, uma variável de membro estática ou uma variável local estática de tipo nativo podem ser marcadas com `__declspec(process)`.  
  
 Ao compilar com **/clr: pure**, variáveis marcados de acordo com o processo também devem ser declarados como `const`. Isso assegura que as variáveis por processo não sejam alteradas em um domínio de aplicativo, gerando resultados inesperados em outro domínio de aplicativo. O primário se destina a uso de `__declspec(process)` é habilitar a inicialização do tempo de compilação de uma variável global, a variável de membro estático ou a variável local estática em **/clr: pure**.  
  
 `process`só é válido durante a compilação com [/clr](../build/reference/clr-common-language-runtime-compilation.md) ou **/clr: pure** e não é válido durante a compilação com **/CLR: safe**.  
  
 Se quiser que cada domínio de aplicativo tenha sua própria cópia de uma variável global, use [appdomain](../cpp/appdomain.md).  
  
 Consulte [domínios do aplicativo e do Visual C++](../dotnet/application-domains-and-visual-cpp.md) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
