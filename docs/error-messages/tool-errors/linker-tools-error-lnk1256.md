---
title: Ferramentas de vinculador LNK1256 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- xml
- LNK1256
dev_langs:
- C++
helpviewer_keywords:
- LNK1256
ms.assetid: 55b64b2b-a56b-436c-a55e-ec9c6dcb050e
caps.latest.revision: 9
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
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 5e29e6100b57531c7a29f84e7c0feac53f20cec9
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="linker-tools-error-lnk1256"></a>Erro das Ferramentas de Vinculador LNK1256
Falha na operação do ALINK: motivo  
  
 Um motivo comum para LNK1256 é um número de versão incorreto para um assembly. O valor 65535 não é permitido para nenhuma parte do número de versão do assembly. O intervalo válido para versões de assembly é 0 - 65534.  
  
 LNK1256 também pode ser causado se ALINK não puder localizar o contêiner de chave denominado. Excluir o contêiner de chave e adicioná-lo novamente para o CSP de nome forte usando [Sn.exe (ferramenta de nome forte)](http://msdn.microsoft.com/Library/c1d2b532-1b8e-4c7a-8ac5-53b801135ec6).  
  
 Outro motivo para LNK1256 é uma incompatibilidade de versão entre o vinculador e o Alink.dll. Isso pode ser causado por uma instalação corrompida do Visual Studio. Use **programas e recursos** no painel de controle do Windows para reparar ou reinstalar o Visual Studio.  
  
 A amostra a seguir gera LNK1256:  
  
```  
// LNK1256.cpp  
// compile with: /clr /LD  
// LNK1256 expected  
[assembly:System::Reflection::AssemblyVersionAttribute("1.0.65535")];  
public class CMyClass {  
public:  
   int value;  
};  
```
