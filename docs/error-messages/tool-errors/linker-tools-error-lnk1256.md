---
title: Ferramentas de vinculador LNK1256 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- xml
- LNK1256
dev_langs: C++
helpviewer_keywords: LNK1256
ms.assetid: 55b64b2b-a56b-436c-a55e-ec9c6dcb050e
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bbbb14e4f4fdef63b58bdef5ecafcfe0b045f412
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1256"></a>Erro das Ferramentas de Vinculador LNK1256
Falha na operação do ALINK: motivo  
  
 Um motivo comum para LNK1256 é um número de versão incorreto para um assembly. O valor 65535 não é permitido para nenhuma parte do número de versão do assembly. O intervalo válido para versões de assembly é 0 - 65534.  
  
 LNK1256 também pode ser causado se ALINK não puder localizar o contêiner de chave denominado. Excluir o contêiner de chave e adicioná-lo novamente para o CSP de nome forte usando [Sn.exe (ferramenta de nome forte)](/dotnet/framework/tools/sn-exe-strong-name-tool).  
  
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