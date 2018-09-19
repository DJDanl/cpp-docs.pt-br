---
title: Ferramentas de vinculador LNK1256 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- xml
- LNK1256
dev_langs:
- C++
helpviewer_keywords:
- LNK1256
ms.assetid: 55b64b2b-a56b-436c-a55e-ec9c6dcb050e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a711343eaf64a9ef1c46a5044cb3d6a2f84c5f7a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46050639"
---
# <a name="linker-tools-error-lnk1256"></a>Erro das Ferramentas de Vinculador LNK1256

Falha na operação do ALINK: motivo

Um motivo comum para LNK1256 é um número de versão incorreto para um assembly. O valor 65535 não é permitido para nenhuma parte do número de versão do assembly. O intervalo válido para versões de assembly é 0 – 65534.

LNK1256 também pode ser causado se ALINK não puder localizar o contêiner de chave denominado. Excluir o contêiner de chave e adicioná-lo novamente ao CSP de nome forte usando [Sn.exe (ferramenta de nome forte)](/dotnet/framework/tools/sn-exe-strong-name-tool).

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