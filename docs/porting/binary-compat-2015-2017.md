---
title: "Compatibilidade binária de C++ entre o Visual Studio 2015 e o Visual Studio 2017 | Microsoft Docs"
ms.custom: 
ms.date: 09/21/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- binary compatibility, Visual C++
ms.assetid: 591580f6-3181-4bbe-8ac3-f4fbaca949e6
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f534432fbf7ff723cac1448bc3a26474f3b323bb
ms.sourcegitcommit: c770a343def04ae77522708387c3f7c470e49969
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/08/2018
---
# <a name="c-binary-compatibility-between-visual-studio-2015-and-visual-studio-2017"></a>Compatibilidade binária de C++ entre o Visual Studio 2015 e o Visual Studio 2017


Em versões anteriores do Visual Studio, não havia garantia de compatibilidade binária entre arquivo-objetos (OBJs), bibliotecas estáticas (LIBs), bibliotecas dinâmicas (DLLs) e executáveis (EXEs) compilados com versões diferentes do conjunto de ferramentas do computador e das bibliotecas de tempo de execução. Isso mudou no Visual Studio 2017. No Visual Studio 2015 e no Visual Studio 2017, o número principal do conjunto de ferramentas do C++ é 14 (v140 para Visual Studio 2015 e v141 para Visual Studio 2017). Isso reflete o fato de que tanto as bibliotecas de tempo de execução quanto os aplicativos compilados com uma das versões do compilador apresentam, em grande parte, compatibilidade binária. Isso significa, por exemplo, que você pode criar uma DLL no Visual Studio 2017 e consumi-lo em um aplicativo compilado com o Visual Studio 2015 ou usar as bibliotecas redistribuíveis do Visual Studio 2017 com o aplicativo compilado usando o conjunto de ferramentas de 2015.  

Há duas exceções a essa regra. Não há garantia de compatibilidade binária nesses casos:  

1) Quando as bibliotecas estáticas ou arquivos-objetos são compilados com a opção /GL de compilador.  

2) Ao consumir bibliotecas criadas com um conjunto de ferramentas cuja versão é maior que o conjunto de ferramentas usado para compilar e vincular o aplicativo. Por exemplo, um programa que é compilado e vinculado com o conjunto de ferramentas 19.12 pode consumir bibliotecas que são compiladas com as versões de 19.0 até 19.12. A vinculação de programas versão 19.x não é compatível com bibliotecas produzidas pelo Visual Studio 2013 ou anterior.


## <a name="see-also"></a>Consulte também  

[Histórico de alterações do Visual C++](..\porting\visual-cpp-change-history-2003-2015.md)


