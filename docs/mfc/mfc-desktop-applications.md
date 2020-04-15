---
title: Aplicativos para desktop do MFC
ms.date: 07/28/2019
f1_keywords:
- MFC
helpviewer_keywords:
- libraries, MFC
- class libraries, MFC
- MFC, about MFC
ms.assetid: 7101cb18-a681-495c-8f2b-069ad20c72f7
ms.openlocfilehash: 3811fdcf278129ee72872ea489b42f8389957761
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359348"
---
# <a name="mfc-desktop-applications"></a>Aplicativos para desktop do MFC

A Biblioteca MFC (Microsoft Foundation Class) fornece um invólucro orientado a objetos sobre grande parte das APIs Win32 e COM. Embora possa ser usado para criar aplicativos de desktop muito simples, é mais útil quando você precisa desenvolver interfaces de usuário mais complexas com vários controles. Você pode usar o MFC para criar aplicativos com interfaces de usuário no estilo Office. Para obter documentação na própria plataforma Windows, consulte a [documentação do Windows](/windows/index). Para obter informações sobre a construção de aplicativos Windows em C++ sem MFC, consulte [Criar aplicativos do Windows de desktop usando a API Win32](/windows/win32/index).

O MFC Reference abrange as classes, funções globais, variáveis globais e macros que compõem a Microsoft Foundation Class Library.

Os gráficos de hierarquia individuais incluídos em cada classe são úteis para localizar classes base. A Referência MFC geralmente não descreve funções de membros herdados ou operadores herdados. Para obter informações sobre essas funções, consulte as classes base retratadas nos diagramas de hierarquia.

A documentação de cada classe inclui uma visão geral da classe, um resumo de membros por categoria e tópicos para as funções dos membros, operadores sobrecarregados e membros de dados.

Os membros de classe públicas e protegidas são documentados apenas quando são normalmente usados em programas de aplicativos ou classes derivadas. Consulte os arquivos de cabeçalho da classe para obter uma lista completa de membros da classe.

> [!IMPORTANT]
> As classes MFC e seus membros não podem ser usados em aplicativos executados no ambiente Windows Runtime.
>
> Bibliotecas MFC (DLLs) para codificação de caracteres multibytes (MBCS) não estão mais incluídas no Visual Studio, mas estão disponíveis como um complemento do Visual Studio. Para obter mais informações, consulte [MFC MBCS DLL Add-on](mfc-mbcs-dll-add-on.md).

## <a name="in-this-section"></a>Nesta seção

[Conceitos](mfc-concepts.md)<br/>
Artigos conceituais sobre temas de MFC.

[Gráfico da hierarquia](hierarchy-chart.md)<br/>
Detalha visualmente as relações de classe na biblioteca de aula.

[Visão geral da classe](class-library-overview.md)<br/>
Lista as classes na Biblioteca MFC de acordo com a categoria.

[Passo a passo](walkthroughs-mfc.md)<br/>
Contém artigos que o guiam através de várias tarefas associadas aos recursos da biblioteca DoM.

[Notas Técnicas](mfc-technical-notes.md)<br/>
Fornece links para tópicos especializados, escritos pela equipe de desenvolvimento do MFC, na biblioteca de aulas.

[Personalização para MFC](customization-for-mfc.md)<br/>
Fornece algumas dicas para personalizar sua aplicação MFC.

[Classes](reference/mfc-classes.md)<br/>
Fornece links e informações de arquivos de cabeçalho para as classes MFC.

[Classes Internas](reference/internal-classes.md)<br/>
Usado internamente em MFC. Para completude, esta seção descreve essas classes internas, mas elas não se destinam a ser usadas diretamente em seu código.

[Macros e globais](reference/mfc-macros-and-globals.md)<br/>
Fornece links para as macros e funções globais na Biblioteca MFC.

[Estruturas, estilos, retornos de chamada e mapas de mensagem](reference/structures-styles-callbacks-and-message-maps.md)<br/>
Fornece links para as estruturas, estilos, retornos de chamadas e mapas de mensagens usados pela Biblioteca MFC.

[Assistentes e caixas de diálogo do MFC](reference/mfc-wizards-and-dialog-boxes.md)<br/>
Um guia para os recursos no Visual Studio para criar aplicativos MFC.

[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)<br/>
Como usar arquivos de recursos para gerenciar dados estáticos da interface do usuário, como strings de interface de interface e layout da caixa de diálogo.

## <a name="related-sections"></a>Seções relacionadas

[Categorias de Gráficos de Hierarquia](hierarchy-chart-categories.md)<br/>
Descreve o gráfico de hierarquia do MFC por categoria.

[Classes compartilhadas ATL/MFC](../atl-mfc-shared/atl-mfc-shared-classes.md)<br/>
Fornece links para classes compartilhadas entre MFC e ATL.

[MFC Amostras](../overview/visual-cpp-samples.md#mfc-samples)<br/>
Fornece links para amostras que demonstram como usar o MFC.

[Referência de bibliotecas do Visual C++](../standard-library/cpp-standard-library-reference.md)<br/>
Fornece links para várias bibliotecas fornecidas com Visual C++, incluindo ATL, MFC e OLE DB, biblioteca em tempo de execução do C e a biblioteca do padrão C++.

[Depurando no Visual Studio](/visualstudio/debugger/debugging-in-visual-studio)<br/>
Fornece links para usar o depurador do Visual Studio para corrigir erros de lógica em seu aplicativo ou procedimentos armazenados.

## <a name="see-also"></a>Confira também

[MFC e ATL](mfc-and-atl.md)
