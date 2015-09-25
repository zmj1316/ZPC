
# F:\Workspace\ASM\Soft\assembler\parsetab.py
# This file is automatically generated. Do not edit.
_tabversion = '3.5'

_lr_method = 'LALR'

_lr_signature = '591D90DE09CCFBEBA514BD02DA9B8940'
    
_lr_action_items = {'LABLE':([0,1,2,7,8,9,10,13,14,15,],[1,1,1,-6,-10,-7,-9,-5,-8,-4,]),'HEX':([4,12,],[8,8,]),'OP':([0,1,2,7,8,9,10,13,14,15,],[4,4,4,-6,-10,-7,-9,-5,-8,-4,]),'FLAG':([4,12,],[9,14,]),'DEC':([4,12,],[10,10,]),'REG':([4,11,12,],[11,12,15,]),'$end':([2,3,5,6,7,8,9,10,13,14,15,],[-1,0,-3,-2,-6,-10,-7,-9,-5,-8,-4,]),}

_lr_action = {}
for _k, _v in _lr_action_items.items():
   for _x,_y in zip(_v[0],_v[1]):
      if not _x in _lr_action:  _lr_action[_x] = {}
      _lr_action[_x][_k] = _y
del _lr_action_items

_lr_goto_items = {'program':([0,1,2,],[3,5,6,]),'IMME':([4,12,],[7,13,]),'IR':([0,1,2,],[2,2,2,]),}

_lr_goto = {}
for _k, _v in _lr_goto_items.items():
   for _x, _y in zip(_v[0], _v[1]):
       if not _x in _lr_goto: _lr_goto[_x] = {}
       _lr_goto[_x][_k] = _y
del _lr_goto_items
_lr_productions = [
  ("S' -> program","S'",1,None,None,None),
  ('program -> IR','program',1,'p_expression_program','asm.py',134),
  ('program -> IR program','program',2,'p_expression_program','asm.py',135),
  ('program -> LABLE program','program',2,'p_expression_program','asm.py',136),
  ('IR -> OP REG REG REG','IR',4,'p_expression_R','asm.py',140),
  ('IR -> OP REG REG IMME','IR',4,'p_expression_I','asm.py',146),
  ('IR -> OP IMME','IR',2,'p_expression_J','asm.py',153),
  ('IR -> OP FLAG','IR',2,'p_expression_JFLAG','asm.py',158),
  ('IR -> OP REG REG FLAG','IR',4,'p_expression_IFLAG','asm.py',162),
  ('IMME -> DEC','IMME',1,'p_expression_DEC','asm.py',169),
  ('IMME -> HEX','IMME',1,'p_expression_HEX','asm.py',172),
]