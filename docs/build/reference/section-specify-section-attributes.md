---
title: "-SEÇÃO (especificar atributos de seção) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /section
dev_langs: C++
helpviewer_keywords:
- SECTION linker option
- -SECTION linker option
- section attributes
- /SECTION linker option
ms.assetid: 92b69d81-e421-462e-b46f-7d0dff9b9d16
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: e3fd7e844d77b9a92408c0708542a4f8f5edf304
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="section-specify-section-attributes"></a>/SECTION (especificar atributos de seção)
```  
/SECTION:name,[[!]{DEKPRSW}][,ALIGN=#]  
```  
  
## <a name="remarks"></a>Comentários  
 A opção /SECTION altera os atributos de uma seção, sobrescrevendo os atributos definidos quando o arquivo. obj para a seção foi compilado.  
  
 Uma seção em um arquivo executável portátil (PE) é aproximadamente equivalente a um segmento ou os recursos em um novo arquivo executável do (m). Seções contêm códigos ou dados. Ao contrário de segmentos, seções são blocos de memória contígua sem restrições de tamanho. Algumas seções contêm códigos ou dados que seu programa declarados e usa diretamente, enquanto as outras seções de dados serão criadas para você, o vinculador e o Gerenciador de biblioteca (lib.exe) e contêm informações essenciais para o sistema operacional. Para obter mais informações sobre arquivos NE, consulte a Base de dados de Conhecimento o artigo "Formato de cabeçalho de arquivo executável" (Q65122). Você pode encontrar artigos da Base de dados de Conhecimento na MSDN Library ou no [http://support.microsoft.com](http://support.microsoft.com).  
  
 Especifique um dois-pontos (:) e uma seção *nome*. O *nome* diferencia maiusculas de minúsculas.  
  
 Não use os nomes a seguir, pois eles entrarão em conflito com os nomes padrão. Por exemplo, .sdata é usado nas plataformas RISC:  
  
-   .arch  
  
-   .BSS  
  
-   . Data  
  
-   .edata  
  
-   .iData  
  
-   . pData  
  
-   RDATA  
  
-   .reloc  
  
-   . rsrc  
  
-   . sbss  
  
-   .sdata  
  
-   .srdata  
  
-   . Text  
  
-   .XData  
  
 Especifique um ou mais atributos para a seção. Os caracteres de atributo, listados abaixo, não diferenciam maiusculas de minúsculas. Você deve especificar todos os atributos que você deseja ter; a seção um caractere de atributo omitido faz com que esse bit de atributo ser desligado. Se você não especificar a gravação de R, W ou E, a leitura existente, ou executável status permanece inalterado.  
  
 Para negar um atributo, preceda seu caractere com um ponto de exclamação (!). Os significados dos caracteres de atributo são mostrados abaixo.  
  
|Caractere|Atributo|Significado|  
|---------------|---------------|-------------|  
|E|Executar|A seção é executável|  
|R|Ler|Permite operações de leitura em dados|  
|W|Write|Permite operações de gravação de dados|  
|S|Compartilhado|Compartilha a seção entre todos os processos que carregam a imagem|  
|D|Descartáveis|Marca a seção como descartáveis|  
|M|Armazenável em cache|Marca a seção como não armazenável em cache|  
|P|Paginável|Marca a seção como não paginável|  
  
 K e P é peculiares em que os sinalizadores de seção que correspondem a elas são no sentido negativo. Se você especificar uma na seção. Text (/ seção:. Text, K), não haverá nenhuma diferença nos sinalizadores de seção quando você executar [DUMPBIN](../../build/reference/dumpbin-options.md) com o [/HEADERS](../../build/reference/headers.md) opção; ele implicitamente já foi armazenado em cache. Para remover o padrão, especifique /SECTION:.text! K e DUMPBIN revelará características de seção, incluindo "Não armazenado em cache."  
  
 Uma seção no arquivo PE que não tenha E, R ou W definido é provavelmente inválida.  
  
 A ALINHAR *=#*  permite que você especifique um valor de alinhamento para uma determinada seção. Consulte [/ALINHAR](../../build/reference/align-section-alignment.md) para obter mais informações.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção para o **opções adicionais** caixa.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)