---
title: "/ZC:referenceBinding (Aplicar regras de associação de referência) | Microsoft Docs"
ms.custom: 
ms.date: 12/13/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- referenceBinding
- /Zc:referenceBinding
dev_langs: C++
helpviewer_keywords:
- -Zc compiler options (C++)
- referenceBinding
- Enforce reference binding rules
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: 0c6cfaac-9c2a-41a3-aa94-64ca8ef261fc
caps.latest.revision: "1"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0d3d352394b61f95e083a2e6e6f0d888fe210b37
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="zcreferencebinding-enforce-reference-binding-rules"></a>/ZC:referenceBinding (Aplicar regras de associação de referência)
Quando o **/Zc:referenceBinding** opção for especificada, o compilador não permite uma referência não const lvalue associar a um temporário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Zc:referenceBinding[-]  
```  
  
## <a name="remarks"></a>Comentários  
Se **/Zc:referenceBinding** for especificado, o compilador seção 8.5.3 do C++ 11 padrão e não permite expressões que associam um tipo definido pelo usuário temporário para uma referência não const lvalue. Por padrão, ou se **/Zc:referenceBinding-** for especificado, o compilador permite tais expressões como uma extensão da Microsoft, mas é emitido um aviso de nível 4. Para segurança de código, portabilidade e conformidade, é recomendável que você use **/Zc:referenceBinding**. O [/ permissivo-](permissive-standards-conformance.md) opção de compilador implicitamente define esta opção, mas ele pode ser substituído usando **/Zc:referenceBinding-**.  
  
## <a name="example"></a>Exemplo  
  
Este exemplo mostra a extensão da Microsoft que permite que um temporário de um tipo definido pelo usuário a ser associado a uma referência não const lvalue.
```cpp  
// zcreferencebinding.cpp
struct S {
};

void f(S&) {
}

S g() {
    return S{};
}

void main() {
    S& s = g();         // warning C4239 at /W4
    const S& cs = g();  // okay, bound to const ref
    f(g());             // Extension: error C2664 only if /Zc:referenceBinding
}
```  
  
Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Modificar o **opções adicionais** propriedade incluir **/Zc:referenceBinding** e, em seguida, escolha **Okey**.  
  
## <a name="see-also"></a>Consulte também  
[Opções do compilador](../../build/reference/compiler-options.md)   
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
[/ZC (conformidade)](../../build/reference/zc-conformance.md)