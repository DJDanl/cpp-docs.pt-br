---
title: Filosofia de Design da classe geral | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.mfc
dev_langs:
- C++
helpviewer_keywords:
- designing classes [MFC]
- MFC, Windows API
- Visual C, Windows API calls
- classes [MFC], MFC class design
- Windows API [MFC], and MFC
ms.assetid: e6861ae0-1581-4d9c-9ddf-63f9afcdb913
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8fe64ee4d9e6fc678d97c3e9fe37a85e53807541
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46416637"
---
# <a name="general-class-design-philosophy"></a>Filosofia de design da classe geral

Microsoft Windows foi projetado muito antes que a linguagem C++ se tornou popular. Como milhares de aplicativos usam a interface de programação de aplicativo (API) do Windows da linguagem C, essa interface será mantida no futuro. Nenhuma interface do Windows C++, portanto, deve ser criado sobre a API de linguagem C de procedimentos. Isso garante que aplicativos C++ seja capazes de coexistir com aplicativos C.

A biblioteca Microsoft Foundation Class é uma interface orientada a objeto para o Windows que cumpra as metas de design a seguir:

- Redução significativa no esforço necessário para escrever um aplicativo para Windows.

- Velocidade de execução comparável da linguagem C API.

- Sobrecarga de tamanho mínimo de código.

- Capacidade de chamar qualquer função de C do Windows diretamente.

- Conversão simplificada dos aplicativos existentes de C para C++.

- Capacidade de aproveitar da base existente do Windows da linguagem C experiência em programação.

- Facilitar o uso da API do Windows com C++ do que com C.

- Mais fácil e ainda usar abstrações poderosos do complicado recursos, como controles ActiveX, suporte de banco de dados, impressão, as barras de ferramentas e barras de status.

- True a API do Windows para C++ que usa com eficiência os recursos da linguagem C++.

Para obter mais informações sobre o design da biblioteca MFC, consulte:

- [A estrutura de aplicativo](../mfc/application-framework.md)

- [Relacionamento com a API da linguagem C](../mfc/relationship-to-the-c-language-api.md)

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)

