---
title: safebuffers | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- safebuffers_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword (C++), safebuffers
- safebuffers __declspec keyword
ms.assetid: 0b0dce14-4523-44d2-8070-5dd0fdabc618
caps.latest.revision: 13
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
ms.openlocfilehash: ceb7d5796002bd54055b74d56a136706890494c4
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="safebuffers"></a>safebuffers
**Seção específica da Microsoft**  
  
 Diz para o compilador não inserir verificações de segurança de excesso de buffer para uma função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__declspec( safebuffers )  
```  
  
## <a name="remarks"></a>Comentários  
 O **/GS** opção de compilador faz com que o compilador testar saturações de buffer inserindo verificações de segurança na pilha. Os tipos de estruturas de dados que estão qualificados para verificações de segurança descritos em [/GS (verificação de segurança do Buffer)](../build/reference/gs-buffer-security-check.md). Para obter mais informações sobre a detecção de estouro de buffer, consulte [compilador verifica em profundidade de segurança](http://go.microsoft.com/fwlink/?linkid=7260) no site do MSDN.  
  
 Uma análise de código manual por especialista ou uma análise externa pode determinar que a função está protegida contra o excesso de buffer. Nesse caso, você pode suprimir as verificações de segurança para uma função, aplicando o `__declspec(safebuffers)` palavra-chave para a declaração da função.  
  
> [!CAUTION]
>  As verificações de segurança do buffer fornecem a proteção de segurança importante e têm uma influência insignificante no desempenho. Portanto, recomendamos que você não suprime, exceto em casos raros em que o desempenho de uma função for um problema crítico e a função é comprovadamente segura.  
  
## <a name="inline-functions"></a>Funções embutidas  
 Um *principal função* pode usar um [inlining](inline-functions-cpp.md) palavra-chave para inserir uma cópia de um *função secundária*. Se o `__declspec(safebuffers)` palavra-chave é aplicada a uma função, a detecção de estouro de buffer é suprimida para essa função. No entanto, inlining afeta o `__declspec(safebuffers)` palavra-chave das seguintes maneiras.  
  
 Suponha que o **/GS** opção de compilador é especificada para ambas as funções, mas a principal função especifica o `__declspec(safebuffers)` palavra-chave. As estruturas de dados na função secundária a tornam elegível para verificações de segurança, e a função não suprime essas verificações. Nesse caso:  
  
-   Especifique o [forceinline](inline-functions-cpp.md) palavra-chave na função secundária para forçar o compilador embutido funcionar independentemente otimizações do compilador.  
  
-   Porque a função secundária está qualificada para verificações de segurança, verificações de segurança também são aplicadas para a função primária, mesmo que ele especifica o `__declspec(safebuffers)` palavra-chave.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como usar o `__declspec(safebuffers)` palavra-chave.  
  
```  
// compile with: /c /GS  
typedef struct {  
    int x[20];  
} BUFFER;  
static int checkBuffers() {  
    BUFFER cb;  
    // Use the buffer...  
    return 0;  
};  
static __declspec(safebuffers)   
    int noCheckBuffers() {  
    BUFFER ncb;  
    // Use the buffer...  
    return 0;  
}  
int wmain() {  
    checkBuffers();  
    noCheckBuffers();  
    return 0;  
}  
```  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [inline, inline, \__forceinline](inline-functions-cpp.md)   
 [strict_gs_check](../preprocessor/strict-gs-check.md)
