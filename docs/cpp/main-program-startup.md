---
title: "principal: inicialização de programa | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- vc.main.startup
- _tmain
dev_langs: C++
helpviewer_keywords:
- program startup [C++]
- entry points, program
- wmain function
- _tmain function
- startup code, main function
- main function, program startup
ms.assetid: f9581cd6-93f7-4bcd-99ec-d07c3c107dd4
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1fbb3d19101358012df795000907a0b3e8139601
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="main-program-startup"></a>main: inicialização do programa
Uma função especial chamada `main` é o ponto inicial de execução de todos os programas do C e C++. Se você estiver gravando o código que obedeça ao modelo de programação [!INCLUDE[TLA#tla_unicode](../atl-mfc-shared/reference/includes/tlasharptla_unicode_md.md)], você pode usar `wmain`, que é a versão de caractere amplo de `main`.  
  
 A função `main` não é predefinido pelo compilador. Ela deve ser fornecida no texto do programa.  
  
 A sintaxe de declaração para `main` é  
  
```  
int main();  
```  
  
 ou, opcionalmente,  
  
```  
int main(int argc, char *argv[], char *envp[]);  
```  
  
## <a name="microsoft-specific"></a>Específico da Microsoft  
 A sintaxe de declaração para `wmain` é a seguinte:  
  
```  
int wmain( );  
```  
  
 ou, opcionalmente,  
  
```  
int wmain(int argc, wchar_t *argv[], wchar_t *envp[]);  
```  
  
 Você também pode usar `_tmain`, que é definido em TCHAR.h. `_tmain` resolve a `main` a menos que o _UNICODE esteja definido. Nesse caso, `_tmain` resolve a `wmain`.  
  
 Como alternativa, as funções `main` e `wmain` podem ser declaradas como retornando `void` (nenhum valor de retorno). Se você declarar `main` ou `wmain` como retornando `void`, você não pode retornar um código de saída para o processo pai ou o sistema operacional usando um [retornar](../cpp/return-statement-in-program-termination-cpp.md) instrução. Para retornar um código de saída quando `main` ou `wmain` está declarado como `void`, você deve usar o [sair](../cpp/exit-function.md) função.  
  
**Fim da seção específica da Microsoft**  
 Os tipos para `argc` e `argv` são definidos pela linguagem. Os nomes `argc`, `argv` e `envp` são tradicionais, mas não são necessários pelo compilador. Para obter mais informações e um exemplo, consulte [definições de argumento](../cpp/argument-definitions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Usando wmain em vez main](../cpp/using-wmain-instead-of-main.md)   
 [Restrições da função main](../cpp/main-function-restrictions.md)