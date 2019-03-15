---
title: Erro das Ferramentas de Vinculador LNK1256
ms.date: 11/04/2016
f1_keywords:
- LNK1256
helpviewer_keywords:
- LNK1256
ms.assetid: 55b64b2b-a56b-436c-a55e-ec9c6dcb050e
ms.openlocfilehash: 47c20f24a2fe26cc96d5efcf359652a40af508ee
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57811531"
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