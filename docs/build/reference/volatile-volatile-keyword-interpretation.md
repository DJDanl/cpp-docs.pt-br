---
title: "-volátil (interpretação da palavra-chave volatile) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /volatile:iso
- /volatile:ms
- /volatile
dev_langs: C++
helpviewer_keywords:
- /volatile compiler option
- /volatile compiler option [C++]
- -volatile compiler option
- volatile compiler option [C++]
- volatile compiler option
- -volatile compiler option [C++]
ms.assetid: 9d08fcc6-5bda-44c8-8151-8d8d54f164b8
caps.latest.revision: "15"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 0e5d138f93aad3603215c3268c2723e0d421b84d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="volatile-volatile-keyword-interpretation"></a>/volatile (Interpretação da palavra-chave volatile)
Especifica como o [volátil](../../cpp/volatile-cpp.md) palavra-chave é interpretada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/volatile:{iso|ms}  
```  
  
## <a name="arguments"></a>Arguments  
 **/volatile:ISO**  
 Seleciona estrita `volatile` semântica conforme definido pela linguagem C++ padrão ISO. Semântica de aquisição/liberação não está garantida em acessos voláteis. Se o compilador tem como alvo ARM, essa é a interpretação padrão `volatile`.  
  
 **/volatile:MS**  
 Seleciona Microsoft estendida `volatile` semântica, que adicione memória ordenação garantias além da linguagem C++ padrão ISO. Semântica de aquisição/liberação é garantida em acessos voláteis. No entanto, essa opção também força o compilador gere barreiras de memória de hardware, que podem adicionar uma sobrecarga significativa no ARM e outras arquiteturas de ordenação de memória fracas. Se o compilador tem como alvo qualquer plataforma exceto ARM, essa é a interpretação padrão de `volatile`.  
  
## <a name="remarks"></a>Comentários  
 É altamente recomendável que você use **/volatile:iso** juntamente com os primitivos de sincronização explícita e intrínsecos do compilador ao lidar com a memória que é compartilhada entre threads. Para obter mais informações, consulte [volátil](../../cpp/volatile-cpp.md).  
  
 Se você porta código existente ou alterar essa opção no meio de um projeto, pode ser útil habilitar o aviso [C4746](../../error-messages/compiler-warnings/compiler-warning-c4746.md) para identificar os locais de código que são afetados pela diferença na semântica.  
  
 Não há nenhum `#pragma` equivalente para controlar essa opção.  
  
### <a name="to-set-the-volatile-compiler-option-in-visual-studio"></a>Para definir o /volatile opção de compilador no Visual Studio  
  
1.  Abra o **páginas de propriedade** caixa de diálogo para o projeto. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  No **opções adicionais** caixa, adicione `/volatile:iso` ou `/volatile:ms`.  
  
## <a name="see-also"></a>Consulte também  
 [volátil](../../cpp/volatile-cpp.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)