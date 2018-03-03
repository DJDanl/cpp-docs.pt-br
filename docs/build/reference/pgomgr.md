---
title: pgomgr | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- pgomgr program
- profile-guided optimizations, pgomgr
ms.assetid: 74589126-df18-42c9-8739-26d60e148d6a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8cbb9a4f8b92a1cd495e1312c1aa8a8f77cefcd3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="pgomgr"></a>pgomgr
Adiciona dados de perfil de um ou mais arquivos. PGC para o arquivo. PGD.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
pgomgr [options] pgcfiles pgdfile  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `options`  
 As opções a seguir podem ser especificadas para pgomgr:  
  
 **/Help —**exibe as opções disponíveis pgomgr (abreviação de /?).  
  
 **/clear —**faz com que o arquivo. PGD limpo de todas as informações de perfil. Não é possível especificar um. PGC arquivo quando **/limpar** for especificado.  
  
 **detalhes**— exibe as estatísticas detalhadas, incluindo informações de cobertura de gráfico de fluxo.  
  
 **Resumo**— exibe de estatísticas por função.  
  
 **/Unique**— quando usado com **resumo**, causas decorado nomes de função para exibir.  O padrão, quando é exclusivo não usado, é para nomes de função não decorados a ser exibido.  
  
 **/ mesclagem**[**:***n*]**—**faz com que os dados no arquivo. PGC ou arquivos a ser adicionado ao arquivo. PGD.  O parâmetro opcional,  *n* , permite que você especifique hat os dados deve ser adicionado  *n*  vezes.  Por exemplo, se um cenário geralmente seria realizado 6 horas, você pode fazer isso vez em uma execução de teste e adicioná-lo para o arquivo. PGD seis vezes com **pgomgr /merge:6**.  
  
 `pgcfiles`  
 . PGC um ou mais arquivos cujos dados de perfil que você deseja mesclar o arquivo. PGD. Você pode especificar um arquivo. PGC único ou vários arquivos. PGC. Se você não especificar todos os arquivos. PGC, pgomgr mesclará todos os arquivos. PGC cujos nomes de arquivo são o mesmo que o arquivo. PGD.  
  
 `pgdfile`  
 O arquivo. PGD na qual você estiver mesclando dados do arquivo. PGC ou arquivos.  
  
## <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Você pode iniciar essa ferramenta apenas o [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)] prompt de comando. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos.  
  
## <a name="example"></a>Exemplo  
 No exemplo a seguir, o arquivo. PGD foi limpo de dados de perfil.  
  
```  
pgomgr /clear myapp.pgd  
```  
  
 No exemplo a seguir, os dados do perfil em myapp1.pgc foi adicionados para o arquivo. PGD 3 vezes.  
  
```  
pgomgr /merge:3 myapp1.pgc myapp.pgd  
```  
  
 No exemplo a seguir, os dados de perfil de todos os arquivos. PGC de # myapp são adicionados ao arquivo myapp.pgd.  
  
```  
pgomgr -merge myapp1.pgd  
```  
  
## <a name="see-also"></a>Consulte também  
 [Ferramentas para otimização guiada por perfil manual](../../build/reference/tools-for-manual-profile-guided-optimization.md)