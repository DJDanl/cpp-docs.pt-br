---
title: component | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc-pragma.component
- component_CPP
dev_langs:
- C++
helpviewer_keywords:
- component pragma
- pragmas, component
ms.assetid: 7b66355e-3201-4c14-8190-f4a2a81a604a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3edb2f68b479eeadca777e0707dd96e148d13fe8
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="component"></a>componente
Controla a coleta de informações de navegação ou informações sobre dependências nos arquivos de origem.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      #pragma component( browser, { on | off }[, references [, name ]] )  
#pragma component( minrebuild, on | off )  
#pragma component( mintypeinfo, on | off )  
```  
  
## <a name="remarks"></a>Comentários  
  
## <a name="browser"></a>Browser  
 Você pode ativar ou desativar a coleta e pode especificar nomes a serem ignorados à medida que as informações são coletadas.  
  
 O uso de on ou off controla a coleta de informações de navegação do pragma em diante. Por exemplo:  
  
```  
#pragma component(browser, off)  
```  
  
 interrompe a coleta de informações de navegação pelo compilador.  
  
> [!NOTE]
>  Para ativar a coleta de informações de procura com este pragma [informações de pesquisa devem ser habilitadas pela primeira vez](../build/reference/building-browse-information-files-overview.md).  
  
 O **referências** opção pode ser usada com ou sem o *nome* argumento. Usando **referências** sem *nome* ativa ou desativa a coleta de referências (outras informações de procura continuam a ser coletado, porém). Por exemplo:  
  
```  
#pragma component(browser, off, references)  
```  
  
 interrompe a coleta de informações sobre referências pelo compilador.  
  
 Usando **referências** com *nome* e **off** impede que as referências a *nome* apareçam na janela de informações de procura. Use essa sintaxe para ignorar nomes e tipos nos quais você não está interessado e para reduzir o tamanho dos arquivos de informações de navegação. Por exemplo:  
  
```  
#pragma component(browser, off, references, DWORD)  
```  
  
 ignora as referências a **DWORD** desse ponto em diante. Você pode ativar a coleta de referências a `DWORD` ligue usando **em**:  
  
```  
#pragma component(browser, on, references, DWORD)  
```  
  
 Essa é a única maneira de retomar a coleta de referências a *nome*; você deve ativar explicitamente em qualquer *nome* que você tiver desativado.  
  
 Para impedir que o pré-processador expandindo *nome* (como expandir **nulo** para **0**), coloque aspas:  
  
```  
#pragma component(browser, off, references, "NULL")  
```  
  
## <a name="minimal-rebuild"></a>Recompilação mínima  
 O recurso de recompilação mínima do Visual C++ requer que o compilador crie e armazene informações sobre dependências das classes do C++, o que ocupa bastante espaço em disco. Para economizar espaço em disco, você pode usar `#pragma component( minrebuild, off )` sempre que você não precisa coletar informações de dependência, por exemplo, nos arquivos de cabeçalho inalterados. Inserir `#pragma component(minrebuild, on)` depois inalteráveis classes para ativar a coleta de dependência de volta no.  
  
## <a name="reduce-type-information"></a>Reduzir informações de tipo  
 O **mintypeinfo** opção reduz as informações de depuração para a região especificada. O volume dessas informações é considerável, afetando arquivos .pdb e .obj. Não é possível depurar classes e estruturas na região de mintypeinfo. O uso da opção mintypeinfo pode ser útil para evitar o seguinte aviso:  
  
```  
LINK : warning LNK4018: too many type indexes in PDB "filename", discarding subsequent type information  
```  
  
 Para obter mais informações, consulte o [habilitar recriar mínimo](../build/reference/gm-enable-minimal-rebuild.md) (/ Gm) a opção de compilador.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)