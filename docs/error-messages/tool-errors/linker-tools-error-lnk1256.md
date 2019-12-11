---
title: Erro das Ferramentas de Vinculador LNK1256
ms.date: 11/04/2016
f1_keywords:
- LNK1256
helpviewer_keywords:
- LNK1256
ms.assetid: 55b64b2b-a56b-436c-a55e-ec9c6dcb050e
ms.openlocfilehash: bedf96262944d59737a39a942021cdec9445f3b8
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74990949"
---
# <a name="linker-tools-error-lnk1256"></a>Erro das Ferramentas de Vinculador LNK1256

Falha na operação do ALINK: motivo

Um motivo comum para LNK1256 é um número de versão incorreto para um assembly. O valor 65535 não é permitido para nenhuma parte do número de versão do assembly. O intervalo válido para as versões de assembly é 0-65534.

LNK1256 também pode ser causado se ALINK não puder localizar o contêiner de chave denominado. Exclua o contêiner de chave e adicione-o novamente ao CSP de nome forte usando [sn. exe (Strong Name Tool)](/dotnet/framework/tools/sn-exe-strong-name-tool).

Outro motivo para LNK1256 é uma incompatibilidade de versão entre o vinculador e o Alink.dll. Isso pode ser causado por uma instalação corrompida do Visual Studio. Use **programas e recursos** no painel de controle do Windows para reparar ou reinstalar o Visual Studio.

A amostra a seguir gera LNK1256:

```cpp
// LNK1256.cpp
// compile with: /clr /LD
// LNK1256 expected
[assembly:System::Reflection::AssemblyVersionAttribute("1.0.65535")];
public class CMyClass {
public:
   int value;
};
```
