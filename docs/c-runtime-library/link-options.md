---
title: Opções de link
ms.date: 11/04/2016
helpviewer_keywords:
- nothrownew.obj
- newmode.obj
- noenv.obj
- psetargv.obj
- legacy_stdio_float_rounding.obj
- loosefpmath.obj
- smallheap.obj
- fp10.obj
- nochkclr.obj
- chkstk.obj
- pcommode.obj
- pnoenv.obj
- link options [C++]
- invalidcontinue.obj
- pnothrownew.obj
- pwsetargv.obj
- pinvalidcontinue.obj
- wsetargv.obj
- binmode.obj
- setargv.obj
- noarg.obj
- pnewmode.obj
- commode.obj
- pthreadlocale.obj
- pbinmode.obj
- threadlocale.obj
- pnoarg.obj
ms.assetid: 05b5a77b-9dd1-494b-ae46-314598c770bb
ms.openlocfilehash: ea71faab639a8c0a09d6e332618dd7e09159a4e5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81351110"
---
# <a name="link-options"></a>Opções de link

O diretório lib CRT inclui vários arquivos de objeto pequenos que habilitam recursos específicos de CRT sem qualquer alteração de código. Eles são chamados de “opções de link”, pois você só precisa adicioná-los à linha de comando do vinculador para usá-los.

As versões de modo puro CLR desses objetos são preteridos no Visual Studio 2015 e sem suporte no Visual Studio 2017. Use as versões regulares para código nativo e /clr.

|Nativo e /clr|Modo puro|Descrição|
|----------------------|---------------|-----------------|
|binmode.obj|pbinmode.obj|Define o modo padrão de conversão de arquivo como binário. Consulte [_fmode](../c-runtime-library/fmode.md).|
|chkstk.obj|n/d|Oferece verificação de pilha e suporte a alloca quando o CRT não está sendo usado.|
|commode.obj|pcommode.obj|Define o sinalizador de confirmação global como "confirmação". Consulte [fopen, _wfopen](../c-runtime-library/reference/fopen-wfopen.md) e [fopen_s, _wfopen_s](../c-runtime-library/reference/fopen-s-wfopen-s.md).|
|exe_initialize_mta.lib|n/d|Inicializa o apartment MTA durante a inicialização do EXE, que permite o uso de objetos COM em ponteiros inteligentes globais. Como essa opção perde uma referência de apartment MTA durante o desligamento, não a use para DLLs. O vínculo a isso é equivalente a incluir combase.h e definir _EXE_INITIALIZE_MTA. |
|fp10.obj|n/d|Altera o controle de precisão padrão para 64 bits. Consulte [Suporte de Ponto Flutuante](../c-runtime-library/floating-point-support.md).|
|invalidcontinue.obj|pinvalidcontinue.obj|Define um manipulador de parâmetro inválido padrão que não realiza nenhuma atividade, isto é, parâmetros inválidos passados para funções CRT serão definidos como errno e retornarão um resultado de erro.|
|legacy_stdio_float_rounding.obj|n/d|A impressão de valores de ponto flutuante (por exemplo, ao usar [printf](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)) com o Windows 10 19041 Universal C Runtime foi corrigida. Ele agora arredonda corretamente números de pontos flutuantes exatamente representáveis, e respeita o arredondamento de ponto flutuante solicitado pela [fesetenv](../c-runtime-library/reference/fesetenv1.md). Esta atualização de comportamento está disponível no Visual Studio 2019 versão 16.2 e posterior. O comportamento legado é usado em versões anteriores do Visual Studio, ou fornecendo esta opção de link.|
|loosefpmath.obj|n/d|Garante que códigos de ponto flutuante tolerem valores desnormalizados.|
|newmode.obj|pnewmode.obj|Faz com que o [malloc](../c-runtime-library/reference/malloc.md) chame o novo manipulador em caso de falha. Consulte [_set_new_mode](../c-runtime-library/reference/set-new-mode.md), [_set_new_handler](../c-runtime-library/reference/set-new-handler.md), [calloc](../c-runtime-library/reference/calloc.md) e [realloc](../c-runtime-library/reference/realloc.md).|
|noarg.obj|pnoarg.obj|Desabilita todo o processamento de argc e argv.|
|nochkclr.obj|n/d|Não faz nada. Remover do seu projeto.|
|noenv.obj|pnoenv.obj|Desabilita a criação de um ambiente em cache para o CRT.|
|nothrownew.obj|pnothrownew.obj|Habilita a versão de não lançamento de new no CRT. Consulte [Operadores new e delete](../cpp/new-and-delete-operators.md).|
|setargv.obj|psetargv.obj|Habilita a expansão de curinga da linha de comando. Consulte [Expandindo Argumentos de Curinga](../c-language/expanding-wildcard-arguments.md).|
|threadlocale.obj|pthreadlocale.obj|Habilita a localidade por thread para todos os novos threads por padrão.|
|wsetargv.obj|pwsetargv.obj|Habilita a expansão de curinga da linha de comando. Consulte [Expandindo Argumentos de Curinga](../c-language/expanding-wildcard-arguments.md).|

## <a name="see-also"></a>Confira também

- [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
