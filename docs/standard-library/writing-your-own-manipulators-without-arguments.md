---
title: "Elaborando os seus próprios manipuladores sem argumentos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- manipulators
ms.assetid: 2dc62d09-45b7-454d-bd9d-55f3c72c206d
caps.latest.revision: 8
author: corob-msft
ms.author: corob
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 276bba3dd5ce5debd926ebbc4ccfaf52c6b92097
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="writing-your-own-manipulators-without-arguments"></a>Elaborando os seus próprios manipuladores sem argumentos
Escrever manipuladores que não usam argumentos não requer a derivação das classes nem o uso de macros complexas. Suponha que sua impressora requer o par \<ESC>[ para entrar no modo negrito. Você pode inserir este par diretamente no fluxo:  
  
```  
cout <<"regular " <<'\033' <<'[' <<"boldface" <<endl;  
```  
  
 Ou você pode definir o manipulador `bold`, que insere os caracteres:  
  
```  
ostream& bold(ostream& os) {  
    return os <<'\033' <<'[';  
}  
cout <<"regular " <<bold <<"boldface" <<endl;  
```  
  
 A função definida globalmente `bold` usa um argumento de referência `ostream` e retorna a referência `ostream`. Não é uma função membro nem um amigo, pois não precisa ter acesso a nenhum elemento de classe privada. A função `bold` se conecta ao fluxo porque o operador `<<` do fluxo está sobrecarregado para aceitar esse tipo de função usando uma declaração semelhante a esta:  
  
```  
_Myt& operator<<(ios_base& (__cdecl *_Pfn)(ios_base&))  
{     // call ios_base manipulator  
 (*_Pfn)(*(ios_base *)this);

    return (*this);

}  
```  
  
 Você pode usar esse recurso para estender outros operadores sobrecarregados. Nesse caso, é incidental que `bold` insira caracteres no fluxo. A função é chamada quando é inserida no fluxo e não necessariamente quando os caracteres adjacentes são impressos. Dessa forma, a impressão poderia ser atrasada por causa do buffer do fluxo.  
  
## <a name="see-also"></a>Consulte também  
 [Fluxos de saída](../standard-library/output-streams.md)


